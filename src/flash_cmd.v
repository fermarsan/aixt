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

// flash_cmd is called after command `aixt flash [flags] source_file`
fn flash_cmd(cmd cli.Command) ! {		
	input_name := os.abs_path(cmd.args[0])		// and source path input
	path := os.dir(input_name)
	base_name := input_name.replace('.v', '') 	// input file base name
	flasher := if cmd.flags.get_string('flasher')! != '' {	// Flasher path
		cmd.flags.get_string('flasher')!
	} else if vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['flasher'][0] != '' {
		vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['flasher'][0]
	} else {
		''
	}
	port := if cmd.flags.get_string('port')! != '' {	// port name
		cmd.flags.get_string('port')!
	} else if vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['port'][0] != '' {
		vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['port'][0]
	} else {
		''
		panic('The flashing port has to be specified as a flag or inside the `v.mod` file.')
	}
	mut project_setup := setup.Setup{}
	ext := match project_setup.backend {
		'nxc' { '' }
		'arduino' { '' }
		else { 'hex' }
	}
	name := if ext == '' { base_name } else { '${base_name}.${ext}' }
	println('Aixt path:\n\t${os.executable()}\n')
	flash(name, flasher, port, project_setup)
	println('\n${name} flashing finished.\n')
}