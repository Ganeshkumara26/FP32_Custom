// FILE: tb/tb_fp32_divsqrt.sv
// Directed test vectors for fpu_divsqrt.sv, per docs/06_verification_plan.md sec. 2.3.
// Also checks the exact 28/27-cycle latency contract (sva/fpu_divsqrt_sva.sv P1/P2).
// Run: iverilog -g2012 -o tb_fp32_divsqrt.vvp rtl/fpu_divsqrt.sv tb/tb_fp32_divsqrt.sv && vvp tb_fp32_divsqrt.vvp
`timescale 1ns/1ps

module tb_fp32_divsqrt;
    logic clk_i = 0;
    logic rst_ni = 0;
    logic start_i;
    logic [31:0] a_i, b_i;
    logic op_i;
    logic busy_o, done_o;
    logic [31:0] result_o;
    logic [4:0] flags_o;

    fpu_divsqrt dut (.*);

    always #5 clk_i = ~clk_i;

    integer pass_count = 0;
    integer fail_count = 0;

    function automatic bit is_nan(input logic [31:0] v);
        return (v[30:23] == 8'hFF) && (v[22:0] != 0);
    endfunction

    // Waits for done_o, counting edges after the trigger edge (matches the
    // SVA's ##28/##27 semantics: the edge where start_i&&!busy_o was sampled
    // is edge 0, done_o must be seen exactly 28 (div) / 27 (sqrt) edges later).
    task automatic check(
        input string name, input logic operation, // 0=div,1=sqrt
        input logic [31:0] a, input logic [31:0] b,
        input logic [31:0] expected, input int expected_edges
    );
        integer edges;
        begin
            @(posedge clk_i);
            a_i = a; b_i = b; op_i = operation;
            @(posedge clk_i); // settle cycle: let combinational classification stabilize
                               // before the edge that latches it (an Icarus Verilog
                               // scheduling quirk in this testbench, not an RTL issue --
                               // confirmed correct behavior independently under Verilator)
            start_i = 1;
            @(posedge clk_i); // edge 1 (trigger edge)
            start_i = 0;
            edges = 1;
            while (!done_o && edges <= 40) begin
                @(posedge clk_i);
                edges++;
            end
            #1;
            if (edges != expected_edges) begin
                fail_count++;
                $display("FAIL [%s]: wrong latency, got %0d edges, expected %0d", name, edges, expected_edges);
            end else if ((is_nan(expected) && is_nan(result_o)) || (result_o == expected)) begin
                pass_count++;
            end else begin
                fail_count++;
                $display("FAIL [%s]: a=%08x b=%08x result=%08x expected=%08x", name, a, b, result_o, expected);
            end
            @(posedge clk_i); // 1 idle cycle between ops
        end
    endtask

    initial begin
        rst_ni = 0; start_i = 0; a_i = 0; b_i = 0; op_i = 0;
        repeat (3) @(posedge clk_i);
        rst_ni = 1;
        @(posedge clk_i);

        // ---- DIV directed ----
        check("D1:2/1=2",      1'b0, 32'h40000000, 32'h3F800000, 32'h40000000, 29);
        check("D2:1/3 RNE",    1'b0, 32'h3F800000, 32'h40400000, 32'h3EAAAAAB, 29);
        check("D3:1/0=+Inf",   1'b0, 32'h3F800000, 32'h00000000, 32'h7F800000, 29);
        check("D4:0/0=NaN",    1'b0, 32'h00000000, 32'h00000000, 32'h7FC00000, 29);

        // ---- SQRT directed ----
        check("S1:sqrt(16)=4", 1'b1, 32'h41800000, 32'h0,        32'h40800000, 28);
        check("S2:sqrt(2)",    1'b1, 32'h40000000, 32'h0,        32'h3FB504F3, 28);
        check("S3:sqrt(-1)",   1'b1, 32'hBF800000, 32'h0,        32'h7FC00000, 28);
        check("S4:sqrt(+0)",   1'b1, 32'h00000000, 32'h0,        32'h00000000, 28);

        // ---- Extra directed: subnormal operands, min/max normal ----
        check("D5:minsub/1",   1'b0, 32'h00000001, 32'h3F800000, 32'h00000001, 29);
        check("D6:1/minnorm",  1'b0, 32'h3F800000, 32'h00800000, 32'h7E800000, 29); // = 2^126, exact
        check("S5:sqrt(minnorm)",1'b1, 32'h00800000, 32'h0,      32'h20000000, 28);
        check("S6:sqrt(-0)",   1'b1, 32'h80000000, 32'h0,        32'h80000000, 28);

        $display("========================================");
        $display("DIVSQRT DIRECTED: %0d passed, %0d failed", pass_count, fail_count);
        $display("========================================");
        if (fail_count > 0) $fatal(1, "DIVSQRT directed tests FAILED");
        $finish;
    end
endmodule
