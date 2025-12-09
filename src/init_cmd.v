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

// init_cmd is called after command `aixt init [flags]`
fn init_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')
	aixt_path := os.dir(os.executable())
	device := if cmd.flags.get_string('device')! != '' {	
		cmd.flags.get_string('device')!
	} else {
		os.input('Input the target device: ')
	}
	if cmd.args.len != 0 {
		println(cmd.help_message())
	} else {
		mut project_setup := setup.Setup{}
		project_setup.load(device)
		src_dir := os.norm_path('${aixt_path}/templates/project/${project_setup.target}/')
		dest_dir := os.norm_path(os.getwd()) 
		name := os.base(dest_dir)
		// println('+++++++++++++++++++++++++ ${name} +++++++++++++++++++++++++')
		list := os.ls(dest_dir) or {
			panic(err)
		}
		for elem in list {	// backups the .v files
			if elem.ends_with('.v') || elem.ends_with('.mod') {
				os.rename(os.norm_path('${dest_dir}/${elem}'), 
						  os.norm_path('${dest_dir}/${elem}.backup')) or {
					panic(err)
				}
			}
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
		os.write_file(os.norm_path('${dest_dir}/v.mod'), 
					  vmod.encode(project_vmod)) or {
			panic(err)
		}
	}
}