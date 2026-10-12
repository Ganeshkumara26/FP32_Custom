// -------------------------------------------------------------------
// fpu_mul.sv — IEEE-754 binary32 pipelined multiplier
// See docs/01_fpu_mul.md for the full design rationale.
//
// 2-stage pipeline, fully pipelined, 1 op/cycle throughput, no stalling.
//   Stage 1 (posedge N   -> regs _s1_) : unpack, classify specials,
//                                        24x24 mantissa multiply
//   Stage 2 (posedge N+1 -> result_o)  : normalize (LZC + shift),
//                                        round (RNE), pack, specials mux
//
// result_o/valid_o are valid on cycle N+2 for an input accepted on cycle N.
// -------------------------------------------------------------------
module fpu_mul (
    input  logic        clk_i,
    input  logic        rst_ni,

    input  logic        valid_i,      // New operands available
    input  logic [31:0] a_i,          // Operand A (IEEE-754 binary32)
    input  logic [31:0] b_i,          // Operand B (IEEE-754 binary32)

    output logic        valid_o,      // Result available (5 cycles after valid_i)
    output logic [31:0] result_o,     // IEEE-754 binary32 result
    output logic [4:0]  flags_o       // {invalid, div_by_zero(0), overflow, underflow, inexact}
);

    // =====================================================================
    // Stage 1: unpack, classify, multiply, compress
    // =====================================================================
    logic        sign_a, sign_b;
    logic [7:0]  exp_a_raw, exp_b_raw;
    logic [22:0] frac_a, frac_b;
    logic        a_is_zero, b_is_zero;
    logic        a_is_inf,  b_is_inf;
    logic        a_is_nan,  b_is_nan;
    logic        a_is_snan, b_is_snan;
    logic        a_is_sub,  b_is_sub;
    logic [23:0] mant_a, mant_b;   // implicit-bit-included (0 for subnormal)
    logic [7:0]  exp_a,  exp_b;    // effective exponent (forced to 1 for subnormal)

    always_comb begin
        sign_a    = a_i[31];
        sign_b    = b_i[31];
        exp_a_raw = a_i[30:23];
        exp_b_raw = b_i[30:23];
        frac_a    = a_i[22:0];
        frac_b    = b_i[22:0];

        a_is_zero = (exp_a_raw == 8'h00) && (frac_a == 23'h0);
        b_is_zero = (exp_b_raw == 8'h00) && (frac_b == 23'h0);
        a_is_inf  = (exp_a_raw == 8'hFF) && (frac_a == 23'h0);
        b_is_inf  = (exp_b_raw == 8'hFF) && (frac_b == 23'h0);
        a_is_nan  = (exp_a_raw == 8'hFF) && (frac_a != 23'h0);
        b_is_nan  = (exp_b_raw == 8'hFF) && (frac_b != 23'h0);
        a_is_snan = a_is_nan && !frac_a[22];   // MSB of fraction clear => signaling
        b_is_snan = b_is_nan && !frac_b[22];
        a_is_sub  = (exp_a_raw == 8'h00) && (frac_a != 23'h0);
        b_is_sub  = (exp_b_raw == 8'h00) && (frac_b != 23'h0);

        mant_a = a_is_sub ? {1'b0, frac_a} : {1'b1, frac_a};
        mant_b = b_is_sub ? {1'b0, frac_b} : {1'b1, frac_b};
        exp_a  = a_is_sub ? 8'h01 : exp_a_raw;
        exp_b  = b_is_sub ? 8'h01 : exp_b_raw;
    end

    logic sign_r_s0;
    assign sign_r_s0 = sign_a ^ sign_b;

    // Biased exponent sum, wide signed to avoid overflow (range roughly -253..382)
    logic signed [10:0] exp_sum_s0;
    assign exp_sum_s0 = $signed({3'b000, exp_a}) + $signed({3'b000, exp_b}) - 11'sd127;

    // 24x24 -> 48 mantissa multiply.
    // SYNTHESIS: verify timing. First-pass behavioral multiply; replace with
    // explicit Booth radix-4 + CSA tree if this does not close at 50 MHz in
    // SCL 180nm (see design doc §8.1).
    logic [47:0] prod_s0;
    assign prod_s0 = mant_a * mant_b;

    // Special-case classification
    logic any_nan_s0, invalid_s0;
    logic result_is_nan_s0, result_is_inf_s0, result_is_zero_s0;
    always_comb begin
        any_nan_s0       = a_is_nan || b_is_nan;
        invalid_s0       = a_is_snan || b_is_snan ||
                            (a_is_inf && b_is_zero) || (a_is_zero && b_is_inf);
        result_is_nan_s0 = any_nan_s0 || (a_is_inf && b_is_zero) || (a_is_zero && b_is_inf);
        result_is_inf_s0 = !result_is_nan_s0 && (a_is_inf || b_is_inf);
        result_is_zero_s0= !result_is_nan_s0 && !result_is_inf_s0 && (a_is_zero || b_is_zero);
    end

    // ---- Stage 1 -> Stage 2 pipeline registers ----
    logic               valid_s1;
    logic               sign_r_s1;
    logic signed [10:0] exp_sum_s1;
    logic [47:0]        prod_s1;
    logic               result_is_nan_s1, result_is_inf_s1, result_is_zero_s1, invalid_s1;

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            valid_s1          <= 1'b0;
            sign_r_s1         <= 1'b0;
            exp_sum_s1        <= '0;
            prod_s1           <= '0;
            result_is_nan_s1  <= 1'b0;
            result_is_inf_s1  <= 1'b0;
            result_is_zero_s1 <= 1'b0;
            invalid_s1        <= 1'b0;
        end else begin
            valid_s1          <= valid_i;
            sign_r_s1         <= sign_r_s0;
            exp_sum_s1        <= exp_sum_s0;
            prod_s1           <= prod_s0;
            result_is_nan_s1  <= result_is_nan_s0;
            result_is_inf_s1  <= result_is_inf_s0;
            result_is_zero_s1 <= result_is_zero_s0;
            invalid_s1        <= invalid_s0;
        end
    end

    // =====================================================================
    // Stage 2: normalize, round (RNE), pack (PIPELINED into 4 extra stages)
    // =====================================================================

    // --- PIPELINE STAGE A: LZC ---
    function automatic [5:0] lzc48(input logic [47:0] v);
        integer i;
        begin
            lzc48 = 6'd48;
            for (i = 0; i < 48; i = i + 1) begin
                if (v[47-i] && (lzc48 == 6'd48)) lzc48 = i[5:0];
            end
        end
    endfunction

    logic [5:0]  nlz_s2;
    assign nlz_s2 = lzc48(prod_s1);

    // Registers A
    logic [5:0]  nlz_regA;
    logic [47:0] prod_regA;
    logic        valid_regA, sign_r_regA, result_is_nan_regA, result_is_inf_regA, result_is_zero_regA, invalid_regA;
    logic signed [10:0] exp_sum_regA;

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            nlz_regA             <= '0;
            prod_regA            <= '0;
            valid_regA           <= 1'b0;
            sign_r_regA          <= 1'b0;
            result_is_nan_regA   <= 1'b0;
            result_is_inf_regA   <= 1'b0;
            result_is_zero_regA  <= 1'b0;
            invalid_regA         <= 1'b0;
            exp_sum_regA         <= '0;
        end else begin
            nlz_regA             <= nlz_s2;
            prod_regA            <= prod_s1;
            valid_regA           <= valid_s1;
            sign_r_regA          <= sign_r_s1;
            result_is_nan_regA   <= result_is_nan_s1;
            result_is_inf_regA   <= result_is_inf_s1;
            result_is_zero_regA  <= result_is_zero_s1;
            invalid_regA         <= invalid_s1;
            exp_sum_regA         <= exp_sum_s1;
        end
    end

    // --- PIPELINE STAGE B: Normalization Shifter ---
    logic [47:0] norm48_s2;
    assign norm48_s2 = prod_regA << nlz_regA;

    logic [23:0] mant24_norm_s2;
    logic        guard_norm_s2, round_norm_s2, sticky_norm_s2;
    assign mant24_norm_s2 = norm48_s2[47:24];
    assign guard_norm_s2  = norm48_s2[23];
    assign round_norm_s2  = norm48_s2[22];
    assign sticky_norm_s2 = |norm48_s2[21:0];

    logic signed [11:0] tent_exp_s2;
    assign tent_exp_s2 = $signed({exp_sum_regA[10], exp_sum_regA}) + 12'sd1 - {6'b0, nlz_regA};

    logic pre_overflow_s2;
    assign pre_overflow_s2 = (tent_exp_s2 >= 12'sd255);

    logic signed [11:0] subshift_raw_s2;
    logic [6:0]          subshift_s2;
    assign subshift_raw_s2 = 12'sd1 - tent_exp_s2;
    assign subshift_s2 = (tent_exp_s2 > 12'sd0) ? 7'd0 :
                          (subshift_raw_s2 > 12'sd38) ? 7'd38 : subshift_raw_s2[6:0];

    logic is_subnormal_path_s2;
    assign is_subnormal_path_s2 = (tent_exp_s2 <= 12'sd0) && !pre_overflow_s2;

    // Registers B
    logic [23:0] mant24_norm_regB;
    logic        guard_norm_regB, round_norm_regB, sticky_norm_regB;
    logic [6:0]  subshift_regB;
    logic        is_subnormal_path_regB, pre_overflow_regB;
    logic [7:0]  tent_exp_regB;
    logic        valid_regB, sign_r_regB, result_is_nan_regB, result_is_inf_regB, result_is_zero_regB, invalid_regB;

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            mant24_norm_regB       <= '0;
            guard_norm_regB        <= 1'b0;
            round_norm_regB        <= 1'b0;
            sticky_norm_regB       <= 1'b0;
            subshift_regB          <= '0;
            is_subnormal_path_regB <= 1'b0;
            pre_overflow_regB      <= 1'b0;
            tent_exp_regB          <= '0;
            valid_regB             <= 1'b0;
            sign_r_regB            <= 1'b0;
            result_is_nan_regB     <= 1'b0;
            result_is_inf_regB     <= 1'b0;
            result_is_zero_regB    <= 1'b0;
            invalid_regB           <= 1'b0;
        end else begin
            mant24_norm_regB       <= mant24_norm_s2;
            guard_norm_regB        <= guard_norm_s2;
            round_norm_regB        <= round_norm_s2;
            sticky_norm_regB       <= sticky_norm_s2;
            subshift_regB          <= subshift_s2;
            is_subnormal_path_regB <= is_subnormal_path_s2;
            pre_overflow_regB      <= pre_overflow_s2;
            tent_exp_regB          <= tent_exp_s2[7:0];
            valid_regB             <= valid_regA;
            sign_r_regB            <= sign_r_regA;
            result_is_nan_regB     <= result_is_nan_regA;
            result_is_inf_regB     <= result_is_inf_regA;
            result_is_zero_regB    <= result_is_zero_regA;
            invalid_regB           <= invalid_regA;
        end
    end

    // --- PIPELINE STAGE C: Subnormal Shift & Pre-rounding logic ---
    logic [25:0] wide_norm_s3;
    assign wide_norm_s3 = {mant24_norm_regB, guard_norm_regB, round_norm_regB};

    logic [25:0] wide_shifted_s3;
    logic        sub_extra_sticky_s3;
    assign wide_shifted_s3 = wide_norm_s3 >> subshift_regB;
    assign sub_extra_sticky_s3 =
        (subshift_regB == 7'd0) ? 1'b0 :
        (|(wide_norm_s3 & ~({26{1'b1}} << subshift_regB)));

    logic [23:0] mant24_pre_s3;
    logic        guard_pre_s3, round_pre_s3, sticky_pre_s3;
    logic [7:0]  exp_pre_s3;

    always_comb begin
        if (is_subnormal_path_regB) begin
            mant24_pre_s3 = wide_shifted_s3[25:2];
            guard_pre_s3  = wide_shifted_s3[1];
            round_pre_s3  = wide_shifted_s3[0];
            sticky_pre_s3 = sticky_norm_regB | sub_extra_sticky_s3;
            exp_pre_s3    = 8'h00;
        end else begin
            mant24_pre_s3 = mant24_norm_regB;
            guard_pre_s3  = guard_norm_regB;
            round_pre_s3  = round_norm_regB;
            sticky_pre_s3 = sticky_norm_regB;
            exp_pre_s3    = tent_exp_regB;
        end
    end

    // Registers C
    logic [23:0] mant24_pre_regC;
    logic        guard_pre_regC, round_pre_regC, sticky_pre_regC;
    logic [7:0]  exp_pre_regC;
    logic        pre_overflow_regC, is_subnormal_path_regC;
    logic        valid_regC, sign_r_regC, result_is_nan_regC, result_is_inf_regC, result_is_zero_regC, invalid_regC;

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            mant24_pre_regC        <= '0;
            guard_pre_regC         <= 1'b0;
            round_pre_regC         <= 1'b0;
            sticky_pre_regC        <= 1'b0;
            exp_pre_regC           <= '0;
            pre_overflow_regC      <= 1'b0;
            is_subnormal_path_regC <= 1'b0;
            valid_regC             <= 1'b0;
            sign_r_regC            <= 1'b0;
            result_is_nan_regC     <= 1'b0;
            result_is_inf_regC     <= 1'b0;
            result_is_zero_regC    <= 1'b0;
            invalid_regC           <= 1'b0;
        end else begin
            mant24_pre_regC        <= mant24_pre_s3;
            guard_pre_regC         <= guard_pre_s3;
            round_pre_regC         <= round_pre_s3;
            sticky_pre_regC        <= sticky_pre_s3;
            exp_pre_regC           <= exp_pre_s3;
            pre_overflow_regC      <= pre_overflow_regB;
            is_subnormal_path_regC <= is_subnormal_path_regB;
            valid_regC             <= valid_regB;
            sign_r_regC            <= sign_r_regB;
            result_is_nan_regC     <= result_is_nan_regB;
            result_is_inf_regC     <= result_is_inf_regB;
            result_is_zero_regC    <= result_is_zero_regB;
            invalid_regC           <= invalid_regB;
        end
    end

    // --- PIPELINE STAGE D: Rounding & Pack ---
    logic round_up_s4;
    assign round_up_s4 = guard_pre_regC & (round_pre_regC | sticky_pre_regC | mant24_pre_regC[0]);

    logic [24:0] mant25_s4;
    assign mant25_s4 = {1'b0, mant24_pre_regC} + {24'b0, round_up_s4};

    logic        carry_s4;
    logic [23:0] mant24_final_s4;
    assign carry_s4 = mant25_s4[24];
    assign mant24_final_s4 = carry_s4 ? mant25_s4[24:1] : mant25_s4[23:0];

    logic [8:0] exp_final9_s4;
    assign exp_final9_s4 = {1'b0, exp_pre_regC} + {8'b0, carry_s4};

    logic inexact_s4, underflow_s4, overflow_s4;
    assign inexact_s4   = guard_pre_regC | round_pre_regC | sticky_pre_regC | pre_overflow_regC;
    assign underflow_s4 = is_subnormal_path_regC && inexact_s4;
    assign overflow_s4  = pre_overflow_regC || (exp_final9_s4 >= 9'd255);

    logic [31:0] computed_result_s4;
    logic [4:0]  computed_flags_s4;
    always_comb begin
        if (overflow_s4) begin
            computed_result_s4 = {sign_r_regC, 8'hFF, 23'h0};
            computed_flags_s4  = {1'b0, 1'b0, 1'b1, 1'b0, 1'b1};
        end else begin
            computed_result_s4 = {sign_r_regC, exp_final9_s4[7:0], mant24_final_s4[22:0]};
            computed_flags_s4  = {1'b0, 1'b0, 1'b0, underflow_s4, inexact_s4};
        end
    end

    logic [31:0] result_comb_s4;
    logic [4:0]  flags_comb_s4;
    always_comb begin
        if (result_is_nan_regC) begin
            result_comb_s4 = 32'h7FC00000;
            flags_comb_s4  = {invalid_regC, 4'b0000};
        end else if (result_is_inf_regC) begin
            result_comb_s4 = {sign_r_regC, 8'hFF, 23'h0};
            flags_comb_s4  = 5'b00000;
        end else if (result_is_zero_regC) begin
            result_comb_s4 = {sign_r_regC, 31'h0};
            flags_comb_s4  = 5'b00000;
        end else begin
            result_comb_s4 = computed_result_s4;
            flags_comb_s4  = computed_flags_s4;
        end
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            valid_o  <= 1'b0;
            result_o <= 32'h0;
            flags_o  <= 5'b0;
        end else begin
            valid_o  <= valid_regC;
            result_o <= result_comb_s4;
            flags_o  <= flags_comb_s4;
        end
    end

endmodule
