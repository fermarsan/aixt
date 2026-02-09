// Author: Fernando M. Santa
// Date: 2025-2026
// ## Description
module main

// Aixt transpiler
import cli
import os
import aixt.setup

// transpile_cmd is called after command `aixt transpile [flags] source_file`
fn transpile_cmd(cmd cli.Command) ! {
	input_name := os.abs_path(cmd.args[0])		// and source path input
	path := os.dir(input_name)

	v_mod := aixt_vmod_load(path)

	mut target := ''
	if cmd.flags.get_string('target')! != '' {	// target name
		target = cmd.flags.get_string('target')!
	} else if v_mod.unknown['target'][0] != '' {
		target = v_mod.unknown['target'][0]
	} else {
		panic('A target name has to be specified as a flag or inside the `v.mod` file.')
	}
	target = target.to_lower()
	mut project_setup := setup.Setup{}
	project_setup.load(target)		
	
	println('Aixt path:\n\t${os.executable()}\n')
	transpile(input_name, project_setup)
	println('\n${input_name} transpiling finished.\n')
}
