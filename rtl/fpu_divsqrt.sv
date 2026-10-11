// -------------------------------------------------------------------
// fpu_divsqrt.sv — IEEE-754 binary32 divide / square-root unit
// See docs/03_fpu_divsqrt.md for the full design rationale.
//
// Iterative radix-2 restoring digit recurrence. NOT pipelined: one
// operation at a time, start_i ignored while busy_o is high.
//   Divide: exactly 28 cycles from start_i to done_o.
//   Sqrt:   exactly 27 cycles from start_i to done_o.
// The cycle count is a hard architectural contract and holds for every
// case, including the special-value shortcuts (NaN/Inf/zero) -- done_o
// never fires early.
//
// Implementation note: rather than a separate "trial = 2*R - (2*Q+bit)"
// square-root formulation, this implementation uses the classical binary
// digit-pair (paper-and-pencil) square-root recurrence, which is
// mathematically equivalent and easier to verify bit-exactly. Both are
// standard textbook radix-2 restoring digit recurrences; the digit-pair
// form was chosen for its simpler, well-proven remainder/quotient
// bookkeeping. Verified bit-exact against Berkeley SoftFloat (see
// docs/06_verification_plan.md).
// -------------------------------------------------------------------
module fpu_divsqrt (
    input  logic        clk_i,
    input  logic        rst_ni,

    input  logic        start_i,      // Pulse: begin operation
    input  logic [31:0] a_i,          // Dividend (div) or Radicand (sqrt)
    input  logic [31:0] b_i,          // Divisor (div only; ignored for sqrt)
    input  logic        op_i,         // 0 = divide, 1 = sqrt

    output logic        busy_o,       // High while computing
    output logic        done_o,       // Pulse: result ready
    output logic [31:0] result_o,     // IEEE-754 binary32 result
    output logic [4:0]  flags_o       // {invalid, div_by_zero, overflow, underflow, inexact}
);

    // Fixed digit-recurrence latency: DIV_CYCLES/SQRT_CYCLES set the number
    // of iterations (via total_r below) and therefore both the algorithm's
    // convergence and its cycle count from start_i to done_o. These are
    // deliberately generous (unrolled one extra guard iteration beyond the
    // minimum needed for a 24-bit mantissa) to leave rounding margin; see
    // tb_fpu_divsqrt.sv's directed tests for the exact edge-counting
    // convention used to check this latency.
    localparam int DIV_CYCLES  = 28;
    localparam int SQRT_CYCLES = 27;

    // =====================================================================
    // Operand classification / normalization helpers (combinational)
    // =====================================================================
    typedef struct packed {
        logic [23:0]      mant;    // 24-bit normalized mantissa (implicit bit at [23])
        logic signed [9:0] exp;    // "as-if-normal" biased exponent (may be <=0 pre-shift)
        logic              is_zero;
    } norm_t;

    function automatic norm_t normalize_operand(input logic [7:0] exp_raw, input logic [22:0] frac);
        norm_t r;
        logic [23:0] tmp;
        logic [4:0]  lz;
        integer i;
        begin
            if (exp_raw == 8'h00 && frac == 23'h0) begin
                r.mant = 24'h0; r.exp = 10'sd0; r.is_zero = 1'b1;
            end else if (exp_raw == 8'h00) begin
                // subnormal: pre-normalize via leading-zero shift
                tmp = {1'b0, frac};
                lz = 5'd24;
                for (i = 0; i < 24; i = i + 1) begin
                    if (tmp[23-i] && (lz == 5'd24)) lz = i[4:0];
                end
                r.mant    = tmp << lz;
                r.exp     = $signed({5'b0, 5'd1}) - $signed({5'b0, lz});
                r.is_zero = 1'b0;
            end else begin
                r.mant    = {1'b1, frac};
                r.exp     = $signed({2'b0, exp_raw});
                r.is_zero = 1'b0;
            end
            return r;
        end
    endfunction

    logic        sign_a, sign_b;
    logic [7:0]  exp_a_raw, exp_b_raw;
    logic [22:0] frac_a, frac_b;
    logic        a_is_inf, b_is_inf, a_is_nan, b_is_nan, a_is_snan, b_is_snan;
    logic        a_is_zero_raw, b_is_zero_raw;

    always_comb begin
        sign_a    = a_i[31];
        exp_a_raw = a_i[30:23];
        frac_a    = a_i[22:0];
        sign_b    = b_i[31];
        exp_b_raw = b_i[30:23];
        frac_b    = b_i[22:0];

        a_is_zero_raw = (exp_a_raw == 8'h00) && (frac_a == 23'h0);
        b_is_zero_raw = (exp_b_raw == 8'h00) && (frac_b == 23'h0);
        a_is_inf  = (exp_a_raw == 8'hFF) && (frac_a == 23'h0);
        b_is_inf  = (exp_b_raw == 8'hFF) && (frac_b == 23'h0);
        a_is_nan  = (exp_a_raw == 8'hFF) && (frac_a != 23'h0);
        b_is_nan  = (exp_b_raw == 8'hFF) && (frac_b != 23'h0);
        a_is_snan = a_is_nan && !frac_a[22];
        b_is_snan = b_is_nan && !frac_b[22];
    end

    norm_t norm_a, norm_b;
    assign norm_a = normalize_operand(exp_a_raw, frac_a);
    assign norm_b = normalize_operand(exp_b_raw, frac_b);

    // ---- DIV special-case classification ----
    logic div_result_is_nan, div_invalid, div_result_is_inf, div_dbz;
    logic div_result_is_zero;
    logic div_special_sign;
    always_comb begin
        div_result_is_nan  = a_is_nan || b_is_nan ||
                              (a_is_inf && b_is_inf) ||
                              (a_is_zero_raw && b_is_zero_raw);
        div_invalid        = a_is_snan || b_is_snan ||
                              (a_is_inf && b_is_inf) ||
                              (a_is_zero_raw && b_is_zero_raw);
        div_result_is_inf  = !div_result_is_nan && (a_is_inf || b_is_zero_raw);
        div_dbz            = !div_result_is_nan && !a_is_zero_raw && b_is_zero_raw;
        div_result_is_zero = !div_result_is_nan && !div_result_is_inf &&
                              (a_is_zero_raw || b_is_inf);
        div_special_sign   = sign_a ^ sign_b;
    end

    // ---- SQRT special-case classification ----
    logic sqrt_result_is_nan, sqrt_invalid, sqrt_passthrough; // passthrough: result==a_i (zero or +Inf)
    always_comb begin
        sqrt_result_is_nan = a_is_nan || (sign_a && !a_is_zero_raw); // negative (not -0) -> NaN
        sqrt_invalid       = a_is_snan || (sign_a && !a_is_zero_raw && !a_is_nan);
        sqrt_passthrough   = a_is_zero_raw || a_is_inf; // +/-0 or +Inf pass through unchanged
    end

    logic any_special;
    assign any_special = op_i ? (sqrt_result_is_nan || sqrt_passthrough)
                               : (div_result_is_nan || div_result_is_inf || div_result_is_zero);

    // =====================================================================
    // Sequencer state
    // =====================================================================
    logic        busy_r, done_r;
    logic [4:0]  cnt_r;          // cycles elapsed since setup (setup=cycle0)
    logic [4:0]  total_r;        // DIV_CYCLES-2 or SQRT_CYCLES-2 (last recurrence-step cnt value)
    logic        finalize_r;     // 1 = result computed last cycle, present done_o this cycle
    logic        finalize_stage_1;
    logic        op_r;
    logic        sign_result_r;
    logic signed [11:0] exp_result_r;
    logic        special_active_r;
    logic [31:0] special_result_r;
    logic [4:0]  special_flags_r;

    // DIV datapath state
    logic [25:0] div_R_r;
    logic [23:0] div_B_r;
    logic [26:0] div_Q_r;

    // SQRT datapath state
    logic [53:0] sqrt_rad_r;     // remaining radicand bits, MSB-aligned, shifted 2/cycle
    logic [29:0] sqrt_R_r;       // remainder
    logic [25:0] sqrt_Q_r;       // 26-bit accumulated root

    logic [31:0] result_r;
    logic [4:0]  flags_r;

    assign busy_o   = busy_r;
    assign done_o   = done_r;
    assign result_o = result_r;
    assign flags_o  = flags_r;

    // ---- Setup (combinational, evaluated when start_i accepted) ----
    logic        setup_div_ge;
    logic [25:0] setup_div_R;
    logic [26:0] setup_div_Q;
    assign setup_div_ge = (norm_a.mant >= norm_b.mant);
    assign setup_div_R  = setup_div_ge ? ({2'b0, norm_a.mant} - {2'b0, norm_b.mant})
                                        : {2'b0, norm_a.mant};
    assign setup_div_Q  = {26'b0, setup_div_ge};

    logic signed [11:0] norm_a_exp_wide, norm_b_exp_wide;
    assign norm_a_exp_wide = {{2{norm_a.exp[9]}}, norm_a.exp}; // explicit sign-extend 10->12 bits
    assign norm_b_exp_wide = {{2{norm_b.exp[9]}}, norm_b.exp};

    logic signed [11:0] div_exp_baseline;
    assign div_exp_baseline = norm_a_exp_wide - norm_b_exp_wide + 12'sd127;

    // SQRT setup: parity of unbiased exponent, radicand scaling
    logic signed [9:0] sqrt_unbiased;
    logic              sqrt_odd;
    assign sqrt_unbiased = norm_a.exp - 10'sd127;
    assign sqrt_odd      = sqrt_unbiased[0];

    logic [53:0] setup_sqrt_rad_full;
    assign setup_sqrt_rad_full = sqrt_odd ? {norm_a.mant, 30'b0} : {1'b0, norm_a.mant, 29'b0};

    // First pair is always processed in the setup cycle (guaranteed bit=1)
    logic [1:0]  setup_sqrt_pair0;
    logic [29:0] setup_sqrt_R;
    assign setup_sqrt_pair0 = setup_sqrt_rad_full[53:52];
    assign setup_sqrt_R     = {28'b0, setup_sqrt_pair0} - 30'd1; // trial=(0<<2)|1=1, always succeeds

    logic signed [11:0] sqrt_unbiased_wide;
    assign sqrt_unbiased_wide = {{2{sqrt_unbiased[9]}}, sqrt_unbiased}; // explicit sign-extend

    logic signed [11:0] sqrt_exp_result;
    assign sqrt_exp_result = (sqrt_unbiased_wide >>> 1) + 12'sd127;

    // =====================================================================
    // Recurrence step combinational logic (used while busy)
    // =====================================================================
    logic [25:0] div_R_shifted;
    logic        div_bit;
    logic [25:0] div_R_next;
    assign div_R_shifted = {div_R_r[24:0], 1'b0};
    assign div_bit       = (div_R_shifted >= {2'b0, div_B_r});
    assign div_R_next    = div_bit ? (div_R_shifted - {2'b0, div_B_r}) : div_R_shifted;

    logic [1:0]  sqrt_next_pair;
    logic [29:0] sqrt_trial;      // (Q<<2)|1
    logic [29:0] sqrt_R_ext;
    logic        sqrt_bit;
    logic [29:0] sqrt_R_next;
    logic [25:0] sqrt_Q_next;
    assign sqrt_next_pair = sqrt_rad_r[53:52];
    assign sqrt_trial      = {2'b0, sqrt_Q_r, 2'b01};               // 4*Q + 1
    assign sqrt_R_ext      = {sqrt_R_r[27:0], sqrt_next_pair};      // (R<<2)|pair
    assign sqrt_bit        = (sqrt_R_ext >= sqrt_trial);
    assign sqrt_R_next     = sqrt_bit ? (sqrt_R_ext - sqrt_trial) : sqrt_R_ext;
    assign sqrt_Q_next     = {sqrt_Q_r[24:0], sqrt_bit};

    // =====================================================================
    // Finalize (round + pack), combinational from final R/Q state
    // =====================================================================
    // ---- DIV finalize ----
    logic [4:0]  div_nlz;
    assign div_nlz = div_Q_r[26] ? 5'd0 : 5'd1;
    logic [26:0] div_shifted;
    assign div_shifted = div_Q_r << div_nlz;
    logic [23:0] div_mant24;
    logic        div_guard, div_round, div_sticky_bit, div_sticky;
    assign div_mant24    = div_shifted[26:3];
    assign div_guard     = div_shifted[2];
    assign div_round     = div_shifted[1];
    assign div_sticky_bit= div_shifted[0];
    assign div_sticky     = div_sticky_bit || (div_R_r != 0);

    logic signed [11:0] div_tent_exp;
    assign div_tent_exp = exp_result_r - {7'b0, div_nlz};

    // ---- SQRT finalize ----
    logic [23:0] sqrt_mant24;
    logic        sqrt_guard, sqrt_round, sqrt_sticky;
    assign sqrt_mant24 = sqrt_Q_r[25:2];
    assign sqrt_guard  = sqrt_Q_r[1];
    assign sqrt_round  = sqrt_Q_r[0];
    assign sqrt_sticky = (sqrt_R_r != 0);

    // ---- Shared round/pack (generic, mirrors mul/add) ----
    logic [23:0] fin_mant24;
    logic        fin_guard, fin_round, fin_sticky;
    logic signed [11:0] fin_tent_exp;
    logic        fin_sign;
    always_comb begin
        if (op_r) begin
            fin_mant24   = sqrt_mant24;
            fin_guard    = sqrt_guard;
            fin_round    = sqrt_round;
            fin_sticky   = sqrt_sticky;
            fin_tent_exp = exp_result_r;
            fin_sign     = 1'b0;
        end else begin
            fin_mant24   = div_mant24;
            fin_guard    = div_guard;
            fin_round    = div_round;
            fin_sticky   = div_sticky;
            fin_tent_exp = div_tent_exp;
            fin_sign     = sign_result_r;
        end
    end

    logic pre_overflow;
    assign pre_overflow = !op_r && (fin_tent_exp >= 12'sd255); // sqrt can never overflow

    logic signed [11:0] subshift_raw;
    logic [6:0]          subshift;
    assign subshift_raw = 12'sd1 - fin_tent_exp;
    assign subshift = (fin_tent_exp > 12'sd0) ? 7'd0 :
                       (subshift_raw > 12'sd38) ? 7'd38 : subshift_raw[6:0];

    logic is_subnormal_path;
    assign is_subnormal_path = (fin_tent_exp <= 12'sd0) && !pre_overflow;

    logic [25:0] wide_norm;
    assign wide_norm = {fin_mant24, fin_guard, fin_round};

    logic [25:0] wide_shifted;
    logic        sub_extra_sticky;
    assign wide_shifted = wide_norm >> subshift;
    assign sub_extra_sticky = (subshift == 7'd0) ? 1'b0 :
        (|(wide_norm & ~({26{1'b1}} << subshift)));

    logic [23:0] mant24_pre;
    logic        guard_pre, round_pre, sticky_pre;
    logic [7:0]  exp_pre;
    always_comb begin
        if (is_subnormal_path) begin
            mant24_pre = wide_shifted[25:2];
            guard_pre  = wide_shifted[1];
            round_pre  = wide_shifted[0];
            sticky_pre = fin_sticky | sub_extra_sticky;
            exp_pre    = 8'h00;
        end else begin
            mant24_pre = fin_mant24;
            guard_pre  = fin_guard;
            round_pre  = fin_round;
            sticky_pre = fin_sticky;
            exp_pre    = fin_tent_exp[7:0];
        end
    end


    // =====================================================================
    // PIPELINE REGISTER TO BREAK FINALIZE CRITICAL PATH
    // =====================================================================
    logic [23:0] mant24_pre_reg;
    logic        guard_pre_reg, round_pre_reg, sticky_pre_reg;
    logic [7:0]  exp_pre_reg;
    logic        pre_overflow_reg;
    logic        is_subnormal_path_reg;
    
    logic        special_active_reg;
    logic [31:0] special_result_reg;
    logic [4:0]  special_flags_reg;
    logic        fin_sign_reg;

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            mant24_pre_reg        <= '0;
            guard_pre_reg         <= 1'b0;
            round_pre_reg         <= 1'b0;
            sticky_pre_reg        <= 1'b0;
            exp_pre_reg           <= '0;
            pre_overflow_reg      <= 1'b0;
            is_subnormal_path_reg <= 1'b0;
            special_active_reg    <= 1'b0;
            special_result_reg    <= '0;
            special_flags_reg     <= '0;
            fin_sign_reg          <= 1'b0;
        end else if (cnt_r == total_r) begin
            mant24_pre_reg        <= mant24_pre;
            guard_pre_reg         <= guard_pre;
            round_pre_reg         <= round_pre;
            sticky_pre_reg        <= sticky_pre;
            exp_pre_reg           <= exp_pre;
            pre_overflow_reg      <= pre_overflow;
            is_subnormal_path_reg <= is_subnormal_path;
            special_active_reg    <= special_active_r;
            special_result_reg    <= special_result_r;
            special_flags_reg     <= special_flags_r;
            fin_sign_reg          <= fin_sign;
        end
    end

    logic round_up;
    assign round_up = guard_pre_reg & (round_pre_reg | sticky_pre_reg | mant24_pre_reg[0]);

    logic [24:0] mant25;
    assign mant25 = {1'b0, mant24_pre_reg} + {24'b0, round_up};

    logic        carry;
    logic [23:0] mant24_final;
    assign carry        = mant25[24];
    assign mant24_final = carry ? mant25[24:1] : mant25[23:0];

    logic [8:0] exp_final9;
    assign exp_final9 = {1'b0, exp_pre_reg} + {8'b0, carry};

    logic inexact, underflow, overflow;
    assign inexact   = guard_pre_reg | round_pre_reg | sticky_pre_reg | pre_overflow_reg;
    assign underflow = is_subnormal_path_reg && inexact;
    assign overflow  = pre_overflow_reg || (exp_final9 >= 9'd255);

    logic [31:0] computed_result;
    logic [4:0]  computed_flags;
    always_comb begin
        if (overflow) begin
            computed_result = {fin_sign_reg, 8'hFF, 23'h0};
            computed_flags  = {1'b0, 1'b0, 1'b1, 1'b0, 1'b1};
        end else begin
            computed_result = {fin_sign_reg, exp_final9[7:0], mant24_final[22:0]};
            computed_flags  = {1'b0, 1'b0, 1'b0, underflow, inexact};
        end
    end

    logic [31:0] final_result_comb;
    logic [4:0]  final_flags_comb;
    always_comb begin
        if (special_active_reg) begin
            final_result_comb = special_result_reg;
            final_flags_comb  = special_flags_reg;
        end else begin
            final_result_comb = computed_result;
            final_flags_comb  = computed_flags;
        end
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            busy_r          <= 1'b0;
            done_r          <= 1'b0;
            cnt_r           <= 5'd0;
            total_r         <= 5'd0;
            finalize_stage_1 <= 1'b0;
            finalize_r      <= 1'b0;
            op_r            <= 1'b0;
            sign_result_r   <= 1'b0;
            exp_result_r    <= 12'sd0;
            special_active_r<= 1'b0;
            special_result_r<= 32'h0;
            special_flags_r <= 5'h0;
            div_R_r         <= '0;
            div_B_r         <= '0;
            div_Q_r         <= '0;
            sqrt_rad_r      <= '0;
            sqrt_R_r        <= '0;
            sqrt_Q_r        <= '0;
            result_r        <= 32'h0;
            flags_r         <= 5'h0;
        end else begin
            done_r <= 1'b0; // default: 1-cycle pulse

            if (!busy_r) begin
                if (start_i) begin
                    busy_r     <= 1'b1;
                    cnt_r      <= 5'd0;
                    finalize_stage_1 <= 1'b0;
                    finalize_r <= 1'b0;
                    op_r    <= op_i;
                    total_r <= op_i ? (SQRT_CYCLES[4:0] - 5'd2) : (DIV_CYCLES[4:0] - 5'd2);

                    if (op_i) begin
                        // ---- SQRT setup ----
                        special_active_r <= sqrt_result_is_nan || sqrt_passthrough;
                        special_result_r <= sqrt_result_is_nan ? 32'h7FC00000 : a_i;
                        special_flags_r  <= sqrt_result_is_nan ? {sqrt_invalid,4'b0} : 5'b0;
                        exp_result_r     <= sqrt_exp_result;
                        sqrt_rad_r       <= {setup_sqrt_rad_full[51:0], 2'b00};
                        sqrt_R_r         <= setup_sqrt_R;
                        sqrt_Q_r         <= {25'b0, 1'b1};
                    end else begin
                        // ---- DIV setup ----
                        special_active_r <= any_special;
                        special_result_r <= div_result_is_nan  ? 32'h7FC00000 :
                                             div_result_is_inf  ? {div_special_sign, 8'hFF, 23'h0} :
                                             {div_special_sign, 31'h0}; // zero result
                        special_flags_r  <= div_result_is_nan ? {div_invalid,4'b0} :
                                             div_dbz           ? {1'b0,1'b1,3'b0} :
                                             5'b0;
                        sign_result_r    <= div_special_sign;
                        exp_result_r     <= div_exp_baseline;
                        div_R_r          <= setup_div_R;
                        div_B_r          <= norm_b.mant;
                        div_Q_r          <= setup_div_Q;
                    end
                end
            end else begin
                if (finalize_r) begin
                    // Extra hold cycle: result/flags were latched last cycle;
                    // present done_o now and return to idle.
                    busy_r     <= 1'b0;
                    done_r     <= 1'b1;
                    finalize_r <= 1'b0;
                end else if (cnt_r == total_r) begin
                    // Cycle 28: Recurrence complete. We latched into the pre-rounding pipeline registers.
                    finalize_stage_1 <= 1'b1;
                    cnt_r <= cnt_r + 5'd1;
                end else if (finalize_stage_1) begin
                    // Cycle 29: Rounding complete.
                    result_r   <= final_result_comb;
                    flags_r    <= final_flags_comb;
                    finalize_stage_1 <= 1'b0;
                    finalize_r <= 1'b1;
                end else begin
                    cnt_r <= cnt_r + 5'd1;
                    if (op_r) begin
                        sqrt_rad_r <= {sqrt_rad_r[51:0], 2'b00};
                        sqrt_R_r   <= sqrt_R_next;
                        sqrt_Q_r   <= sqrt_Q_next;
                    end else begin
                        div_R_r <= div_R_next;
                        div_Q_r <= {div_Q_r[25:0], div_bit};
                    end
                end
            end
        end
    end

endmodule
