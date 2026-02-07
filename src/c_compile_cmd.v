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

	mut target := ''
	if cmd.flags.get_string('target')! != '' {	// target name
		target = cmd.flags.get_string('target')!
	} else if vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['target'][0] != '' {
		target = vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['target'][0]
	} else {
		panic('A target name has to be specified as a flag or inside the `v.mod` file.')
	}
	mut project_setup := setup.Setup{}
	project_setup.load(target)

	mut cc := ''
	if cmd.flags.get_string('c_compiler')! != '' {	// as a flag
		cc = cmd.flags.get_string('c_compiler')!
	} else if vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['cc'][0] != '' {	// inside `v.mod`
		cc = vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['cc'][0]
	} else {	// inside `setup/<target_name>.json`
		$if windows {
			if project_setup.cc['windows_path'] != '' {
				cc = project_setup.cc['windows_path']
			} else if project_setup.cc['path'] != ''{
				cc = project_setup.cc['path']
			} else {
				panic('The C compiler path has to be specified as a flag or inside the `setup/<target>.json` file.')
			}
		} $else {
			if project_setup.cc['path'] != ''{
				cc = project_setup.cc['path']
			} else {
				panic('The C compiler path has to be specified as a flag or inside the `setup/<target>.json` file.')
			}
		}
	}

	cc_flags := if cmd.flags.get_string('cc_flags')! != '' {	// C compiler flags
		cmd.flags.get_string('cc_flags')!
	} else if vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['cc'][1] != '' {
		vmod.from_file(os.norm_path('${path}/v.mod'))!.unknown['cc'][1]
	} else {
		project_setup.cc['args']
	}

	println('Aixt path:\n\t${os.executable()}\n')
	c_compile(base_name, cc, cc_flags, project_setup)
	ext := match project_setup.backend {
		'nxc' { 'nxc' }
		'arduino' { 'ino' }
		else { 'c' }		
	}
	println('\n${base_name}.${ext} compiling finished.\n')
}