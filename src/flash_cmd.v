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

	v_mod := vmod.from_file(os.norm_path('${path}/v.mod')) or { 
		vmod.Manifest {
			name: ''
			description: ''
			version: ''
			license: ''
			dependencies: []
			unknown: { 
				'target': [''], 
				'port': ['/dev/ttyUSB0'], 
				'cc': ['', ''],
				'flasher': ['', '']
			}
		}
	}

	mut target := ''
	if cmd.flags.get_string('target')! != '' {	// target name
		target = cmd.flags.get_string('target')!
	} else if v_mod.unknown['target'][0] != '' {
		target = v_mod.unknown['target'][0]
	} else {
		panic('A target name has to be specified as a flag or inside the `v.mod` file.')
	}
	mut project_setup := setup.Setup{}
	project_setup.load(target)

	mut flasher := ''
	if cmd.flags.get_string('flasher')! != '' {	// as a flag
		flasher = cmd.flags.get_string('flasher')!
	} else if v_mod.unknown['flasher'][0] != '' {	// inside `v.mod`
		flasher = v_mod.unknown['flasher'][0]
	} else {	// inside `setup/<target_name>.json`
		$if windows {
			if project_setup.flasher['windows_path'] != '' {
				flasher = project_setup.flasher['windows_path']
			} else if project_setup.flasher['path'] != ''{
				flasher = project_setup.flasher['path']
			} else {
				panic('The flasher path has to be specified as a flag or inside the `setup/<target>.json` file.')
			}
		} $else {
			if project_setup.flasher['path'] != ''{
				flasher = project_setup.flasher['path']
			} else {
				panic('The flasher path has to be specified as a flag or inside the `setup/<target>.json` file.')
			}
		}
	}

	f_args := if cmd.flags.get_string('f_args')! != '' {	// C compiler args
		cmd.flags.get_string('f_args')!
	} else if v_mod.unknown['flasher'][1] != '' {
		v_mod.unknown['flasher'][1]
	} else {
		project_setup.flasher['args']
	}

	mut port := ''
	if cmd.flags.get_string('port')! != '' {	// port name
		port = cmd.flags.get_string('port')!
	} else if v_mod.unknown['port'][0] != '' {
		port = v_mod.unknown['port'][0]
	} else {
		panic('The flashing port has to be specified as a flag or inside the `v.mod` file.')
	}

	ext := match project_setup.backend {
		'nxc' { '' }
		'arduino' { '' }
		else { 'hex' }
	}
	
	name := if ext == '' { base_name } else { '${base_name}.${ext}' }
	println('Aixt path:\n\t${os.executable()}\n')
	flash(name, flasher, f_args, port, project_setup)
	println('\n${name} flashing finished.\n')
}