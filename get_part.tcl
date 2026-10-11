set parts [get_parts]
if {[llength $parts] > 0} {
    puts "AVAILABLE_PART: [lindex $parts 0]"
} else {
    puts "NO_PARTS_FOUND"
}
