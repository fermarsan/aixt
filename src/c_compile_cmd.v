// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
// Description: This is the main file of the Aixt project.
module main

// Aixt transpiler
import cli
import os
import aixt.setup

// c_compile_cmd is called after command `aixt c_compile [flags] source_file`
fn c_compile_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')
	device := cmd.flags.get_string('device')!	// device name 
	input_name := os.abs_path(cmd.args[0])		// and source path input
	base_name := input_name.replace('.v', '') 	// input file base name
	mut project_setup := setup.Setup{}
	project_setup.load(device)
	if cmd.args.len != 1 {
		println(cmd.help_message())
	} else {
		c_compile(base_name, project_setup)
		ext := match project_setup.backend {
			'nxc' { 'nxc' }
			'arduino' { 'ino' }
			else { 'c' }
		}
		println('\n${base_name}.${ext} compiling finished.\n')
	}
}