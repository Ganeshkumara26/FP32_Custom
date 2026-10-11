create_clock -name clk_i -period 10.0 [get_ports -quiet clk_i]

set_input_delay -clock clk_i 0.0 [get_ports -filter {NAME != clk_i && DIRECTION == "IN"}]
set_output_delay -clock clk_i 0.0 [all_outputs]
