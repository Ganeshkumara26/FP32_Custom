open_project ./vivado_fpu_intalu/fpu_intalu.xpr
open_run synth_1
write_schematic -format pdf -force ./vivado_fpu_intalu/fpu_intalu_synth_schematic.pdf
