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

// flash_cmd is called after command `aixt flash [flags] source_file`
fn flash_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')
	port := cmd.flags.get_string('port')!	// port name 		
	input_name := os.abs_path(cmd.args[0])		// and source path input
	base_name := input_name.replace('.v', '') 	// input file base name
	mut project_setup := setup.Setup{}
	if cmd.args.len != 1 {
		println(cmd.help_message())
	} else {
		ext := match project_setup.backend {
			'nxc' { '' }
			'arduino' { '' }
			else { 'hex' }
		}
		name := if ext == '' { base_name } else { '${base_name}.${ext}' }
		flash(name, port, project_setup)
		println('\n${name} flashing finished.\n')
	}
}