// FILE: tb/tb_fp32_mul.sv
// Directed test vectors for fpu_mul.sv, per docs/06_verification_plan.md sec. 2.1.
// Run: iverilog -g2012 -o tb_fp32_mul.vvp rtl/fpu_mul.sv tb/tb_fp32_mul.sv && vvp tb_fp32_mul.vvp
`timescale 1ns/1ps

module tb_fp32_mul;
    logic clk_i = 0;
    logic rst_ni = 0;
    logic valid_i;
    logic [31:0] a_i, b_i;
    logic valid_o;
    logic [31:0] result_o;
    logic [4:0] flags_o;

    fpu_mul dut (.*);

    always #5 clk_i = ~clk_i;

    integer pass_count = 0;
    integer fail_count = 0;

    function automatic bit is_nan(input logic [31:0] v);
        return (v[30:23] == 8'hFF) && (v[22:0] != 0);
    endfunction

    task automatic check(
        input string name,
        input logic [31:0] a, input logic [31:0] b,
        input logic [31:0] expected, input logic [4:0] expected_flags,
        input bit check_flags
    );
        begin
            @(posedge clk_i);
            valid_i = 1; a_i = a; b_i = b;
            @(posedge clk_i);
            valid_i = 0;
            repeat (4) @(posedge clk_i); // result_o valid now (5 cycles after issue)
            #1;
            if ((is_nan(expected) && is_nan(result_o)) || (result_o == expected)) begin
                if (!check_flags || flags_o == expected_flags) begin
                    pass_count++;
                end else begin
                    fail_count++;
                    $display("FAIL [%s]: a=%08x b=%08x result=%08x (OK) but flags=%b exp_flags=%b",
                              name, a, b, result_o, flags_o, expected_flags);
                end
            end else begin
                fail_count++;
                $display("FAIL [%s]: a=%08x b=%08x result=%08x expected=%08x",
                          name, a, b, result_o, expected);
            end
        end
    endtask

    initial begin
        rst_ni = 0; valid_i = 0; a_i = 0; b_i = 0;
        repeat (3) @(posedge clk_i);
        rst_ni = 1;
        @(posedge clk_i);

        // #1 Identity
        check("1:Identity",        32'h3F800000, 32'h3F800000, 32'h3F800000, 5'b0, 0);
        // #2 Basic
        check("2:Basic 2*3=6",     32'h40000000, 32'h40400000, 32'h40C00000, 5'b0, 0);
        // #3 Zero * finite
        check("3:+0*1.0",          32'h00000000, 32'h3F800000, 32'h00000000, 5'b0, 0);
        // #4 -0 * finite
        check("4:-0*1.0",          32'h80000000, 32'h3F800000, 32'h80000000, 5'b0, 0);
        // #5 Inf * 0
        check("5:Inf*0",           32'h7F800000, 32'h00000000, 32'h7FC00000, 5'b10000, 1);
        // #6 Inf * finite
        check("6:Inf*1.0",         32'h7F800000, 32'h3F800000, 32'h7F800000, 5'b0, 0);
        // #7 NaN propagation (qNaN input: invalid flag must NOT be set, only sNaN does that)
        check("7:NaN*1.0",         32'h7FC00000, 32'h3F800000, 32'h7FC00000, 5'b00000, 1);
        // #8 Overflow
        check("8:MaxNorm*2",       32'h7F7FFFFF, 32'h40000000, 32'h7F800000, 5'b00101, 1);
        // #9 Underflow to subnormal
        check("9:MinNorm*0.5",     32'h00800000, 32'h3F000000, 32'h00400000, 5'b00010, 0); // inexact bit not asserted here since exact
        // #10 Subnormal * 1
        check("10:MinSub*1.0",     32'h00000001, 32'h3F800000, 32'h00000001, 5'b0, 0);
        // #11 Rounding tie (just check it runs; exact value verified by random harness)
        check("11:1+ulp * 1+ulp",  32'h3F800001, 32'h3F800001, 32'h3F800002, 5'b00001, 0);
        // #12 Neg * neg
        check("12:-1*-1",          32'hBF800000, 32'hBF800000, 32'h3F800000, 5'b0, 0);

        $display("========================================");
        $display("MUL DIRECTED: %0d passed, %0d failed", pass_count, fail_count);
        $display("========================================");
        if (fail_count > 0) $fatal(1, "MUL directed tests FAILED");
        $finish;
    end
endmodule
