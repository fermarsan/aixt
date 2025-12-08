// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
// Description: This is the main file of the Aixt project.
module main

// Aixt transpiler
import cli
import os
import v.vmod
import aixt.setup

// transpile_cmd is called after command `aixt transpile [flags] source_file`
fn transpile_cmd(cmd cli.Command) ! {
	input_name := os.abs_path(cmd.args[0])		// and source path input
	path := os.dir(input_name)
	device := if cmd.flags.get_string('device')! != '' {	// device name
		cmd.flags.get_string('device')!
	} else {
		vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['device'][0]
	}
	mut project_setup := setup.Setup{}
	project_setup.load(device)		
	println('Aixt path:\n\t${os.executable()}\n')
	transpile(input_name, project_setup)
	println('\n${input_name} transpiling finished.\n')
}
