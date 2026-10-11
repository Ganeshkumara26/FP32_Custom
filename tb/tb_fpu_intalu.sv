// FILE: tb/tb_fp32_intalu.sv
// Directed test vectors for fpu_intalu.sv, per docs/06_verification_plan.md sec. 2.4
// (ITOF), plus directed coverage for IADD/ISUB/ICMP/IMOV.
// Run: iverilog -g2012 -o tb_fp32_intalu.vvp rtl/fpu_intalu.sv tb/tb_fp32_intalu.sv && vvp tb_fp32_intalu.vvp
`timescale 1ns/1ps

module tb_fp32_intalu;
    logic clk_i = 0;
    logic rst_ni = 0;
    logic valid_i;
    logic [3:0] op_i;
    logic [31:0] a_i, b_i;
    logic [12:0] imm_i;
    logic valid_o;
    logic [31:0] result_o;
    logic cmp_result_o;
    logic zero_o;

    fpu_intalu dut (.*);

    always #5 clk_i = ~clk_i;

    integer pass_count = 0;
    integer fail_count = 0;

    task automatic check(
        input string name, input logic [3:0] op,
        input logic [31:0] a, input logic [31:0] b, input logic [12:0] imm,
        input logic [31:0] expected
    );
        begin
            @(posedge clk_i);
            op_i = op; a_i = a; b_i = b; imm_i = imm;
            @(posedge clk_i); // settle before the edge that registers the output
            valid_i = 1;
            @(posedge clk_i); // result_o valid 1 cycle after issue
            valid_i = 0;
            #1;
            if (result_o == expected) begin
                pass_count++;
            end else begin
                fail_count++;
                $display("FAIL [%s]: a=%08x b=%08x imm=%0d result=%08x expected=%08x",
                          name, a, b, $signed(imm), result_o, expected);
            end
        end
    endtask

    initial begin
        rst_ni = 0; valid_i = 0; op_i = 0; a_i = 0; b_i = 0; imm_i = 0;
        repeat (3) @(posedge clk_i);
        rst_ni = 1;
        @(posedge clk_i);

        // ---- ITOF directed tests ----
        check("ITOF1:0",              4'b0111, 32'h00000000, 0, 0, 32'h00000000);
        check("ITOF2:1",              4'b0111, 32'h00000001, 0, 0, 32'h3F800000);
        check("ITOF3:-1",             4'b0111, 32'hFFFFFFFF, 0, 0, 32'hBF800000);
        check("ITOF4:INT_MAX",        4'b0111, 32'h7FFFFFFF, 0, 0, 32'h4F000000);
        check("ITOF5:INT_MIN",        4'b0111, 32'h80000000, 0, 0, 32'hCF000000);
        // 16777217 = 2^24+1 sits exactly halfway between the two representable
        // float32 values 16777216 (0x4B800000) and 16777218 (0x4B800001); RNE
        // rounds to the even mantissa, which is 16777216. An earlier draft of
        // this test's expected-value table had the odd (non-RNE) result here
        // -- caught by independently recomputing the expected value rather
        // than trusting the original table entry.
        check("ITOF6:16777217",       4'b0111, 32'h01000001, 0, 0, 32'h4B800000);
        check("ITOF7:16777219 tie",   4'b0111, 32'h01000003, 0, 0, 32'h4B800002);

        // ---- IADD/ISUB/ICMP/IMOV directed ----
        check("IADD:5+3",       4'b0100, 32'd5,   0, 13'd3,    32'd8);
        check("IADD:5+(-3)",    4'b0100, 32'd5,   0, -13'sd3,  32'd2);
        check("ISUB:5-3",       4'b0101, 32'd5,   32'd3, 0,    32'd2);
        check("ISUB:wrap",      4'b0101, 32'd0,   32'd1, 0,    32'hFFFFFFFF);
        check("IMOV:imm=100",   4'b1011, 0, 0, 13'd100,        32'd100);
        check("IMOV:imm=-1",    4'b1011, 0, 0, -13'sd1,        32'hFFFFFFFF);

        // ICMP: result_o[0] carries cmp_result_o per this module's design; check cmp_result_o directly
        @(posedge clk_i);
        op_i = 4'b0110; a_i = 32'd3; b_i = 32'd5; imm_i = 0;
        @(posedge clk_i);
        valid_i = 1;
        @(posedge clk_i);
        valid_i = 0;
        #1;
        if (cmp_result_o == 1'b1) pass_count++;
        else begin fail_count++; $display("FAIL [ICMP:3<5]: cmp_result_o=%b expected 1", cmp_result_o); end

        @(posedge clk_i);
        op_i = 4'b0110; a_i = 32'd5; b_i = 32'd3; imm_i = 0;
        @(posedge clk_i);
        valid_i = 1;
        @(posedge clk_i);
        valid_i = 0;
        #1;
        if (cmp_result_o == 1'b0) pass_count++;
        else begin fail_count++; $display("FAIL [ICMP:5<3]: cmp_result_o=%b expected 0", cmp_result_o); end

        // zero_o check
        @(posedge clk_i);
        op_i = 4'b0101; a_i = 32'd7; b_i = 32'd7; imm_i = 0; // ISUB 7-7=0
        @(posedge clk_i);
        valid_i = 1;
        @(posedge clk_i);
        valid_i = 0;
        #1;
        if (zero_o == 1'b1 && result_o == 32'h0) pass_count++;
        else begin fail_count++; $display("FAIL [zero_o:7-7]: zero_o=%b result=%08x", zero_o, result_o); end

        $display("========================================");
        $display("INTALU DIRECTED: %0d passed, %0d failed", pass_count, fail_count);
        $display("========================================");
        if (fail_count > 0) $fatal(1, "INTALU directed tests FAILED");
        $finish;
    end
endmodule
