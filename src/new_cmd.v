// Author: Fernando M. Santa
// Date: 2025-2026
// ## Description
// This is the main file of the Aixt project.
module main

// Aixt transpiler
import cli
import os
import v.vmod
import aixt.setup

// new_cmd is called after command `aixt new [flags]`
fn new_cmd(cmd cli.Command) ! {

	aixt_path := os.dir(os.dir(os.executable()))
	print('Aixt_path:\n\t${aixt_path}\n')

	target := if cmd.flags.get_string('target')! != '' {	
		cmd.flags.get_string('target')!
	} else {
		os.input('Input the target device: ')
	}
	path := if cmd.flags.get_string('folder')! != '' {
		os.abs_path(cmd.flags.get_string('folder')!)	
	} else {
		os.abs_path(os.input('Input your project folder: '))
	}
	name := if cmd.flags.get_string('name')! != '' {
		cmd.flags.get_string('name')!	
	} else {
		os.input('Input your project name: ')
	}
	if cmd.args.len != 0 {
		println(cmd.help_message())
	} else {
		dest_dir := os.norm_path('${os.abs_path(path)}/${name}/') 
		mut project_setup := setup.Setup{}
		project_setup.load(target, dest_dir)
		src_dir := os.norm_path('${aixt_path}/templates/project/${project_setup.target}/')
		if !os.exists(dest_dir) {
			os.mkdir(dest_dir) or { panic(err) }
		}
		os.cp_all(src_dir, dest_dir, true) or { 
			panic(err) 
		}
		if project_setup.backend == 'arduino' { // arduino-cli sketch name requirement
			os.rename(os.norm_path('${dest_dir}/main.v'),
					  os.norm_path('${dest_dir}/${name}.v')) or {
				panic(err)
			}
		}
		// adds the device name to de Makefile
		if os.exists(os.norm_path('${dest_dir}/Makefile')) { 
			mut makefile := os.read_file(os.norm_path('${dest_dir}/Makefile')) or {
				panic(err)
			}
			makefile = makefile.replace('__device_name__', '${project_setup.device}')
			os.write_file(os.norm_path('${dest_dir}/Makefile'), makefile) or {
				panic(err)
			}
		}
		mut project_vmod := vmod.Manifest {
			name:			name
			unknown:		{
				'target':	[project_setup.device]
				'port':		$if linux { ['/dev/ttyUSB0'] } $else { ['COM1'] }
			}
		}
		os.write_file(os.norm_path('${dest_dir}/v.mod'), vmod.encode(project_vmod)) or {
			panic(err)
		}
		// copy the 'device.json' and 'compiler.json' files to the '.setup' directory
		if !os.exists(os.norm_path('${dest_dir}/.setup/') ) {
			os.mkdir(os.norm_path('${dest_dir}/.setup/') ) or { panic(err) }
		}
		os.cp(	// device.json
			os.norm_path('${aixt_path}/setup/${project_setup.target}.json'),
			os.norm_path('${dest_dir}/.setup/'),
			fail_if_exists: false
		    ) or { 
			panic(err) 
		}
		os.cp(	// compiler.json
			os.norm_path('${aixt_path}/${project_setup.compiler_setup_path}'),
			os.norm_path('${dest_dir}/.setup/'),
			fail_if_exists: false
		    ) or { 
			panic(err) 
		}
	}
}