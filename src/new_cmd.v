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

// new_cmd is called after command `aixt new [flags]`
fn new_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')
	aixt_path := os.dir(os.executable())
	device := if cmd.flags.get_string('device')! == '' {	
		os.input('Input the target device: ')
	} else {
		cmd.flags.get_string('device')!
	}
	path := if cmd.flags.get_string('folder')! == '' {	
		os.abs_path(os.input('Input your project folder: '))
	} else {
		os.abs_path(cmd.flags.get_string('folder')!)
	}
	name := if cmd.flags.get_string('name')! == '' {	
		os.input('Input your project name: ')
	} else {
		cmd.flags.get_string('name')!
	}
	if cmd.args.len != 0 {
		println(cmd.help_message())
	} else {
		mut project_setup := setup.Setup{}
		project_setup.load(device)
		src_dir := os.norm_path('${aixt_path}/templates/project/${project_setup.target}/')
		dest_dir := os.norm_path('${os.abs_path(path)}/${name}/') 
		if !os.exists(dest_dir) {
			os.mkdir(dest_dir) or { panic(err) }
		}
		os.cp_all(src_dir, dest_dir, true) or { 
			panic(err) 
		}
		if project_setup.backend == 'arduino' { // arduino-cli sketch name requirement
			os.rename(os.norm_path('${dest_dir}/main.v'), os.norm_path('${dest_dir}/${name}.v')) or {
				panic(err)
			}
		}
		// adds the device name to de Makefile
		if os.exists(os.norm_path('${dest_dir}/Makefile')) { 
			mut makefile := os.read_file(os.norm_path('${dest_dir}/Makefile')) or {
				panic(err)
			}
			makefile = makefile.replace('__device_name__', '${device}')
			os.write_file(os.norm_path('${dest_dir}/Makefile'), makefile) or {
				panic(err)
			}
		}
		mut project_vmod := vmod.Manifest {
			name:			name
			// description:	os.input('Input your project description: ')
			// version:		'0.0.0'
			unknown:		{
				'device':	[device]
				'port':		$if linux { ['/dev/ttyUSB0'] } $else { ['COM1'] }
			}
		}
		os.write_file(os.norm_path('${dest_dir}/v.mod'), vmod.encode(project_vmod)) or {
			panic(err)
		}
	}
}