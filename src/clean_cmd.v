// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
// ## Description
// This is the main file of the Aixt project.
module main

// Aixt transpiler
import cli
import os

// clean_cmd is called after command `aixt clean [flags] source_file`
fn clean_cmd(cmd cli.Command) ! {
	println('Aixt path:\n\t${os.executable()}\n')		
	input_name := os.abs_path(cmd.args[0])		// and source path input
	base_name := input_name.replace('.v', '') 	// input file base name
	if cmd.args.len != 1 {
		println(cmd.help_message())
	} else {
		if os.exists(os.norm_path('${os.dir(base_name)}/Makefile')) {
			println(os.execute('make -f ${os.dir(base_name)}' + os.path_separator + 'Makefile clean').output)
		}
		os.rm('${base_name}.c') or {} // clean c-type files
		os.rm('${base_name}.nxc') or {}
		os.rm('${base_name}.ino') or {}
		$if windows { // and executables
			os.rm('${base_name}.exe') or {}
		} $else {
			os.rm('${base_name}') or {}
		}
		if os.exists(os.norm_path(os.dir(base_name) + '/build/')) {
			os.rmdir_all(os.norm_path(os.dir(base_name) + '/build/')) or { panic(err) }
		}
		// Remove all .c, .cpp, .h, hpp files inside the directory
		files := os.ls(os.dir(base_name)) or { [] }
		for file in files {
			if file.ends_with('.c') || file.ends_with('.cpp')
				|| file.ends_with('.h') || file.ends_with('.hpp') {
				os.rm(os.norm_path('${os.dir(base_name)}/${file}')) or {}
			}
		}
		println('Output files cleaned.')
	}
}