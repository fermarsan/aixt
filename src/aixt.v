// Author: Fernando M. Santa
// Date: 2023-2025
// ## Description
// This is the main file of the Aixt project.
module main

// Aixt transpiler
import cli
import os

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
						name: 			'target'
						abbrev:			't' 
						description: 	'Target device or board.'
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
						name: 			'target'
						abbrev:			't' 
						description: 	'Target device or board.'
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
						name: 			'target'
						abbrev:			't' 
						description: 	'Target device or board.'
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
				description:	'Create new project (v and editor files).'
				execute:		new_cmd
				flags: [
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'target'
						abbrev:			't' 
						description: 	'Target device or board.'
					},
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'folder'
						abbrev:			'f' 
						description: 	'Project folder.'
					},
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'name'
						abbrev:			'n' 
						description: 	'Project name.'
					}
				]
				required_args:	0
				defaults: 		struct {
					man: false
				}
			},
			cli.Command {
				name:			'init'
				description:	'Initialize a project (v and editor files).'
				execute:		init_cmd
				flags: [
					cli.Flag {
						flag:			cli.FlagType.string
						name: 			'target'
						abbrev:			't' 
						description: 	'Target device or board.'
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