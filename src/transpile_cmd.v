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

// transpile_cmd is called after command `aixt transpile [flags] source_file`
fn transpile_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')
	device := if cmd.flags.get_string('device')! != 	// device name
	if devi
	mut project_setup := setup.Setup{}
	project_setup.load(device)
	// println('++++++++++++++++\n${project_setup}\n++++++++++++++++')
	if cmd.args.len != 1 {
		println(cmd.help_message())
	} else {
		input_name := os.abs_path(cmd.args[0])		// and source path input
		transpile(input_name, project_setup)
		println('\n${input_name} transpiling finished.\n')
	}
}