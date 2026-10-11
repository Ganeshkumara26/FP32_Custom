// FILE: sva/fpu_add_sva.sv
// Bind: bind fpu_add fpu_add_sva u_sva (.*);
//
// P5/P5b were revised to match the NaN-canonicalization fix to NEG (see
// docs/02_fpu_add.md sec.6, ENGINEERING_LOG.md B.4): NEG(NaN) now produces
// the fixed canonical value 0xFFC00000 rather than the input NaN's payload
// with the sign bit flipped, so the old single P5 property (unconditional
// bypass_result_o[31] == ~a_i[31]) no longer holds for NaN inputs and has
// been split into P5 (non-NaN case, unchanged rule) and P5b (NaN case,
// checks the canonical output). Not yet run under a simulator with full
// SVA support (only checked by inspection against the RTL and the
// directed testbench vectors) -- verify these bind and pass under
// Xcelium before relying on them.

module fpu_add_sva (
    input logic clk_i, rst_ni,
    input logic valid_i, valid_o,
    input logic [2:0] op_i,
    input logic [31:0] a_i, b_i, result_o,
    input logic bypass_valid_o,
    input logic [31:0] bypass_result_o,
    input logic cmp_lt_o,
    input logic [4:0] flags_o
);

    // P1: ADD/SUB pipeline timing — valid_o follows valid_i by 3 cycles
    logic valid_d1, valid_d2, valid_d3;
    logic is_pipelined;
    assign is_pipelined = (op_i == 3'b000) || (op_i == 3'b001); // ADD or SUB

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            valid_d1 <= 0; valid_d2 <= 0; valid_d3 <= 0;
        end else begin
            valid_d1 <= valid_i && is_pipelined;
            valid_d2 <= valid_d1;
            valid_d3 <= valid_d2;
        end
    end

    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && is_pipelined) |-> ##3 valid_o
    ) else $error("ADD_SVA P1: ADD/SUB valid_o must follow valid_i by 3 cycles");

    // P2: Bypass timing — CMP/ABS/NEG/MIN/MAX produce result in 1 cycle
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && !is_pipelined) |-> ##1 bypass_valid_o
    ) else $error("ADD_SVA P2: bypass ops must produce result in 1 cycle");

    // P3: +Inf + (-Inf) = NaN
    wire a_pos_inf = (a_i == 32'h7F800000);
    wire b_neg_inf = (b_i == 32'hFF800000);
    wire a_neg_inf = (a_i == 32'hFF800000);
    wire b_pos_inf = (b_i == 32'h7F800000);

    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && op_i == 3'b000 && a_pos_inf && b_neg_inf) |-> ##3
            (result_o == 32'h7FC00000 && flags_o[4] == 1'b1)
    ) else $error("ADD_SVA P3: +Inf + (-Inf) must be NaN");

    // P4: ABS clears sign bit (holds for both the ordinary and the
    // canonical-NaN case, since the canonical NaN 0x7FC00000 also has
    // sign bit 0 -- see docs/02_fpu_add.md sec.6 for the NaN-canonicalization
    // history this assertion needed to stay compatible with).
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && op_i == 3'b101) |-> ##1 (bypass_result_o[31] == 1'b0)
    ) else $error("ADD_SVA P4: ABS must clear sign bit");

    // P5: NEG flips sign bit, on non-NaN inputs. NaN inputs are excluded
    // here and checked separately by P5b: NEG canonicalizes any NaN to
    // 0xFFC00000 rather than preserving its payload with the sign flipped
    // (see docs/02_fpu_add.md sec.6) -- a_i[30:0] != 0x7FFFFFFF (i.e. exp
    // != 0xFF) or mantissa == 0 rules out NaN without duplicating the
    // classifier logic here.
    wire a_is_nan_p5 = (a_i[30:23] == 8'hFF) && (a_i[22:0] != 23'd0);
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && op_i == 3'b110 && !a_is_nan_p5)
        |-> ##1 (bypass_result_o[31] == ~a_i[31])
    ) else $error("ADD_SVA P5: NEG must flip sign bit on non-NaN input");

    // P5b: NEG of any NaN is the canonical NaN, sign bit set.
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && op_i == 3'b110 && a_is_nan_p5)
        |-> ##1 (bypass_result_o == 32'hFFC00000)
    ) else $error("ADD_SVA P5b: NEG of a NaN must canonicalize to 0xFFC00000");

    // P6: +0 == -0 for CMP
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && op_i == 3'b010 && a_i == 32'h00000000 && b_i == 32'h80000000)
        |-> ##1 (cmp_lt_o == 1'b0)
    ) else $error("ADD_SVA P6: +0 and -0 must compare equal (neither is less than)");

endmodule
