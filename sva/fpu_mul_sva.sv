// FILE: sva/fpu_mul_sva.sv
// Bind: bind fpu_mul fpu_mul_sva u_sva (.*);
// Source: docs/06_verification_plan.md (reproduced verbatim;
// no changes were needed since it matches the fpu_mul.sv port list exactly).

module fpu_mul_sva (
    input logic clk_i, rst_ni,
    input logic valid_i, valid_o,
    input logic [31:0] a_i, b_i, result_o,
    input logic [4:0] flags_o
);

    // ========================================================================
    // P1: Pipeline timing — valid_o follows valid_i by exactly 5 cycles
    // ========================================================================
    logic [5:1] valid_d;   // valid_d[k] is valid_i delayed by k cycles
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            valid_d <= '0;
        end else begin
            valid_d <= {valid_d[4:1], valid_i};
        end
    end

    assert property (@(posedge clk_i) disable iff (!rst_ni)
        valid_o == valid_d[5]
    ) else $error("MUL_SVA P1: valid_o must track valid_i delayed by 5 cycles");

    // ========================================================================
    // P2: NaN propagation — if either input is NaN, output must be canonical NaN
    // ========================================================================
    wire a_is_nan = (a_i[30:23] == 8'hFF) && (a_i[22:0] != 0);
    wire b_is_nan = (b_i[30:23] == 8'hFF) && (b_i[22:0] != 0);

    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && (a_is_nan || b_is_nan)) |-> ##5 (result_o == 32'h7FC00000)
    ) else $error("MUL_SVA P2: NaN input must produce canonical NaN (0x7FC00000)");

    // ========================================================================
    // P3: Zero × finite — result must be ±0
    // ========================================================================
    wire a_is_zero = (a_i[30:0] == 31'h0);
    wire b_is_zero = (b_i[30:0] == 31'h0);
    wire a_is_inf  = (a_i[30:23] == 8'hFF) && (a_i[22:0] == 0);
    wire b_is_inf  = (b_i[30:23] == 8'hFF) && (b_i[22:0] == 0);
    wire a_is_finite = !a_is_nan && !a_is_inf;
    wire b_is_finite = !b_is_nan && !b_is_inf;

    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && a_is_zero && b_is_finite) |-> ##5 (result_o[30:0] == 31'h0)
    ) else $error("MUL_SVA P3: 0 * finite must be ±0");

    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && b_is_zero && a_is_finite) |-> ##5 (result_o[30:0] == 31'h0)
    ) else $error("MUL_SVA P3b: finite * 0 must be ±0");

    // ========================================================================
    // P4: Inf × 0 = NaN (invalid operation)
    // ========================================================================
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && a_is_inf && b_is_zero) |-> ##5
            (result_o == 32'h7FC00000 && flags_o[4] == 1'b1)
    ) else $error("MUL_SVA P4: Inf * 0 must be NaN + invalid flag");

    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && a_is_zero && b_is_inf) |-> ##5
            (result_o == 32'h7FC00000 && flags_o[4] == 1'b1)
    ) else $error("MUL_SVA P4b: 0 * Inf must be NaN + invalid flag");

    // ========================================================================
    // P5: Sign rule — result sign = a_sign XOR b_sign (for finite non-zero non-NaN)
    // ========================================================================
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (valid_i && a_is_finite && b_is_finite && !a_is_zero && !b_is_zero)
        |-> ##5 (result_o[31] == (a_i[31] ^ b_i[31]))
    ) else $error("MUL_SVA P5: sign of product must be XOR of input signs");

    // ========================================================================
    // P6: Reset behavior — valid_o deasserted after reset
    // ========================================================================
    assert property (@(posedge clk_i)
        (!rst_ni) |=> (!valid_o)
    ) else $error("MUL_SVA P6: valid_o must be 0 after reset");

    // ========================================================================
    // P7: No spurious valid — valid_o only when pipeline has valid data
    // ========================================================================
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        valid_o |-> (valid_d[5])
    ) else $error("MUL_SVA P7: valid_o without valid input 5 cycles ago");

endmodule
