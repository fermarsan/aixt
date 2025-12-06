// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
// Description: This is the main file of the Aixt project.
module main

// Aixt transpiler
import cli
import os
import aixt.setup

// main function for Aixt transpiler.
fn main() {
	mut aixt_cli := cli.Command {
		name: 			'aixt'
		usage:			'[arguments]'
		description: 	description()
		version:		'0.2.3'
		execute:	 	fn (cmd cli.Command) ! {
			println(cmd.help_message())
			return
		}
		commands: [
			cli.Command {
				name:			'transpile'
				usage:			'source_file'
				description:	'Transpiles an Aixt source file to C.'
				execute:		transpile_cmd
				flags: [
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'device'
						abbrev:			'd' 
						description: 	'Target device or board.'
						global: 		true
						required:		true
					}
				]
				required_args:	1
				defaults: 		struct {
					man: false
				}
			},
			cli.Command {
				name:			'c_compile'
				usage:			'source_file'
				description:	'Compile the previosly generated C file.'
				execute:		c_compile_cmd
				flags: [
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'device'
						abbrev:			'd' 
						description: 	'Target device or board.'
						global: 		true
						required:		true
					}
				]
				required_args:	1
				defaults: 		struct {
					man: false
				}
			},
			cli.Command {
				name:			'flash'
				usage:			'source_file'
				description:	'Flash the device with the generated binary file.'
				execute:		flash_cmd
				flags: [
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'port'
						abbrev:			'p' 
						description: 	'Flashing port.'
						global: 		true
						required:		true
					}
				]
				required_args:	1
				defaults: 		struct {
					man: false
				}
			},
			cli.Command {
				name:			'build'
				usage:			'source_file'
				description:	'Build (transpile and compile) an Aixt program.'
				execute:		build_cmd
				flags: [
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'device'
						abbrev:			'd' 
						description: 	'Target device or board.'
						global: 		true
						required:		true
					}
				]
				required_args:	1
				defaults: 		struct {
					man: false
				}
			},
			cli.Command {
				name:			'clean'
				usage:			'source_file'
				description:	'Clean all the generated files (C and executables).'
				execute:		clean_cmd
				required_args:	1
				defaults: 		struct {
					man: false
				}
			},
			cli.Command {
				name:			'new'
				description:	'Create new project (main.v and editor setup files).'
				execute:		new_cmd
				flags: [
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'device'
						abbrev:			'd' 
						description: 	'Target device or board.'
						global: 		true
						required:		true
					},
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'folder'
						abbrev:			'f' 
						description: 	'Project folder.'
						global: 		true
						required:		true
					},
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'name'
						abbrev:			'n' 
						description: 	'Project name.'
						global: 		true
						required:		true
					}
				]
				required_args:	0
				defaults: 		struct {
					man: false
				}
			},
			cli.Command {
				name:			'symlink'
				description:	'Create a symbolic link to the Aixt source file.'
				execute:		symlink_cmd
				required_args:	0
				defaults: 		struct {
					man: false
				}
			}
		]
		defaults: struct {
			man: false
		}
	}
    aixt_cli.setup()
    aixt_cli.parse(os.args)
}

fn new_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')
	aixt_path := os.dir(os.executable())
	device := cmd.flags.get_string('device')!
	path := os.abs_path(cmd.flags.get_string('folder')!)
	name := cmd.flags.get_string('name')!
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
	}
}

fn symlink_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')
	aixt_path := os.dir(os.executable())
	if cmd.args.len != 0 {
		println(cmd.help_message())
	} else {		
		aixt_symlink(aixt_path)
	}
}
