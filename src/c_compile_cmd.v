// Author: Fernando M. Santa
// Date: 2025
// ## Description
// This is the main file of the Aixt project.
module main

// Aixt transpiler
import cli
import os
import v.vmod
import aixt.setup

// c_compile_cmd is called after command `aixt c_compile [flags] source_file`
fn c_compile_cmd(cmd cli.Command) ! {
	input_name := os.abs_path(cmd.args[0])		// and source path input
	path := os.dir(input_name)
	base_name := input_name.replace('.v', '') 	// input file base name
	device := if cmd.flags.get_string('target')! != '' {	// device name
		cmd.flags.get_string('target')!
	} else {
		vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['device'][0]
	}
	mut project_setup := setup.Setup{}
	project_setup.load(device)
	println('Aixt path:\n\t${os.executable()}\n')
	c_compile(base_name, project_setup)
	ext := match project_setup.backend {
		'nxc' { 'nxc' }
		'arduino' { 'ino' }
		else { 'c' }		
	}
	println('\n${base_name}.${ext} compiling finished.\n')
}