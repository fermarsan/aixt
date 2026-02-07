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
	mut device := ''
	if cmd.flags.get_string('target')! != '' {	// device name
		device = cmd.flags.get_string('target')!
	} else if vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['device'][0] != '' {
		device = vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['device'][0]
	} else {
		panic('A target device has to be specified as a flag or inside the `v.mod` file.')
	}
	mut cc := ''
	if cmd.flags.get_string('compiler')! != '' {	// C compiler path
		cc = cmd.flags.get_string('compiler')!
	} else if vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['cc'][0] != '' {
		cc = vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['cc'][0]
	}
	
	// // This way produces an error
	// cc := if cmd.flags.get_string('compiler')! != '' {	// C compiler path
	// 	cmd.flags.get_string('compiler')!
	// } else if vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['cc'][0] != '' {
	// 	vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['cc'][0]
	// } else {
	// 	''
	// }

	mut project_setup := setup.Setup{}
	project_setup.load(device)
	println('Aixt path:\n\t${os.executable()}\n')
	c_compile(base_name, cc, project_setup)
	ext := match project_setup.backend {
		'nxc' { 'nxc' }
		'arduino' { 'ino' }
		else { 'c' }		
	}
	println('\n${base_name}.${ext} compiling finished.\n')
}