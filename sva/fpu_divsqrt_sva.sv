// FILE: sva/fpu_divsqrt_sva.sv
// Bind: bind fpu_divsqrt fpu_divsqrt_sva u_sva (.*);
// Source: docs/06_verification_plan.md (reproduced verbatim;
// matches the fpu_divsqrt.sv port list exactly).

module fpu_divsqrt_sva (
    input logic clk_i, rst_ni,
    input logic start_i, busy_o, done_o, op_i,
    input logic [31:0] a_i, b_i, result_o,
    input logic [4:0] flags_o
);

    // P1: DIVIDE latency is exactly 28 cycles
    property div_latency;
        @(posedge clk_i) disable iff (!rst_ni)
        (start_i && !busy_o && !op_i) |-> ##28 done_o;
    endproperty
    assert property (div_latency)
        else $error("DIVSQRT_SVA P1: DIV must complete in exactly 28 cycles");

    // P2: SQRT latency is exactly 27 cycles
    property sqrt_latency;
        @(posedge clk_i) disable iff (!rst_ni)
        (start_i && !busy_o && op_i) |-> ##27 done_o;
    endproperty
    assert property (sqrt_latency)
        else $error("DIVSQRT_SVA P2: SQRT must complete in exactly 27 cycles");

    // P3: done_o is a single-cycle pulse
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        done_o |=> !done_o
    ) else $error("DIVSQRT_SVA P3: done_o must be a single-cycle pulse");

    // P4: busy_o high during computation
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (start_i && !busy_o) |=> busy_o
    ) else $error("DIVSQRT_SVA P4: busy_o must go high after start");

    // P5: busy_o goes low when done
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        done_o |=> !busy_o
    ) else $error("DIVSQRT_SVA P5: busy_o must go low after done");

    // P6: start_i ignored while busy
    // (No state change occurs — this is a cover property for testing)
    cover property (@(posedge clk_i) disable iff (!rst_ni)
        busy_o && start_i
    );

    // P7: Division by zero → ±Inf, div_by_zero flag
    wire b_is_zero = (b_i[30:0] == 31'h0);
    wire a_is_finite = (a_i[30:23] != 8'hFF) && (a_i[30:0] != 31'h0);

    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (start_i && !busy_o && !op_i && b_is_zero && a_is_finite)
        |-> ##28 (result_o[30:23] == 8'hFF && result_o[22:0] == 23'h0 && flags_o[3] == 1'b1)
    ) else $error("DIVSQRT_SVA P7: x / 0 must be ±Inf with div_by_zero flag");

    // P8: sqrt of negative → NaN, invalid flag
    assert property (@(posedge clk_i) disable iff (!rst_ni)
        (start_i && !busy_o && op_i && a_i[31] && a_i[30:0] != 31'h0)
        |-> ##27 (result_o == 32'h7FC00000 && flags_o[4] == 1'b1)
    ) else $error("DIVSQRT_SVA P8: sqrt(negative) must be NaN + invalid");

    // P9: Reset clears busy
    assert property (@(posedge clk_i)
        !rst_ni |=> (!busy_o && !done_o)
    ) else $error("DIVSQRT_SVA P9: reset must clear busy and done");

endmodule
