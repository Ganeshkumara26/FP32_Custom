set module [lindex $argv 0]
set src_file [lindex $argv 1]
set part [lindex [get_parts] 0]

create_project $module ./vivado_$module -part $part -force
add_files $src_file

# Add constraints file for timing-driven optimization
add_files fpu_constraints.xdc
set_property target_constrs_file fpu_constraints.xdc [current_fileset -constrset]

set_property top $module [current_fileset]
update_compile_order -fileset sources_1

# Synthesis (Rebuilt hierarchy + Retiming to perfectly balance the pipelining)
set_property STEPS.SYNTH_DESIGN.ARGS.FLATTEN_HIERARCHY rebuilt [get_runs synth_1]
#set_property STEPS.SYNTH_DESIGN.ARGS.RETIMING true [get_runs synth_1]
launch_runs synth_1 -jobs 4
wait_on_run synth_1

open_run synth_1 -name synth_1

# Implementation with Aggressive Physical Optimization
set_property STEPS.PHYS_OPT_DESIGN.IS_ENABLED true [get_runs impl_1]
set_property STEPS.PLACE_DESIGN.ARGS.DIRECTIVE Explore [get_runs impl_1]
set_property STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE Explore [get_runs impl_1]
set_property STEPS.ROUTE_DESIGN.ARGS.DIRECTIVE Explore [get_runs impl_1]

launch_runs impl_1 -jobs 4
wait_on_run impl_1

# Reports
open_run impl_1
report_utilization -file ./vivado_$module/${module}_utilization.txt
report_timing_summary -file ./vivado_$module/${module}_timing.txt

# Save canonical results to a dedicated folder
file mkdir ./canonical_results
file copy -force ./vivado_$module/${module}_utilization.txt ./canonical_results/${module}_utilization.txt
file copy -force ./vivado_$module/${module}_timing.txt ./canonical_results/${module}_timing.txt
