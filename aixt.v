// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: aixt.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is the main file of the Aixt project. It works as a make file too.
//
// Usage:
// 1. Run the program using `v run aixt.v command device input_file_name`
import os
import toml
import aixt_pref
import aixt_build

fn main() {
	aixt_path := os.dir(os.args[0]) // aixt base path
	command := os.args[1] // command

	if command in ['help', '--help', '-h'] {
		println(help_message())
	} else {
		device, input_name := os.args[2], os.args[3] // the other parameters
		// base_name := input_name.replace('.aixt', '') // input file base name

		dev_setup_path := '${aixt_path}/devices/${aixt_pref.device_path(device)}setup.toml'
		setup := toml.parse_file(dev_setup_path) or { return } // load the device's setup file
		// backend := aixt_pref.backend_from_string(setup.value('backend').string()) or { return }	// backend

		// cc := $if windows { // C compiler depending on the OS
		// 	setup.value('cc_windows').string()
		// } $else {
		// 	setup.value('cc_linux').string()
		// }

		// mut vpref := &pref.Preferences{}
		// vpref.is_script = true // enable script mode
		// table := ast.new_table()

		// mut parsed := parser.parse_file(path, table, .skip_comments, vpref)
		// mut checker_ := checker.new_checker(table, vpref)
		// checker_.check(parsed)

		match command {
			'transpile', '-t' {
				aixt_build.build_file(input_name, setup)
				println('\n${input_name} was successfully transpiled to C.\n')
			}
			// 'compile', '-c' {
			// 	// mut file_str_list := walk_ext(api_path, '.c').join(' ')
			// 	// println('file_str_list: ${file_str_list}')
			// 	// file_str_list += ' ' + walk_ext(dir(input_name), '.c').join(' ')
			// 	// println('file_str_list: ${file_str_list}')
			// 	// println(execute('${cc} ${file_str_list} -o ${base_name}').output)
			// 	println(execute('${cc} ${base_name}.c -o ${base_name}').output)
			// }
			// 'run', '-r' {
			// 	result := $if windows {
			// 		execute('${base_name}.exe')
			// 	} $else {
			// 		execute('${base_name}')
			// 	}
			// 	println(result.output)
			// }
			// 'build', '-b' {
			// 	println(execute('${python} ${aixtt} ${input_name}').output) // transpile
			// 	// compile_directory(api_path, cc)
			// 	println(execute('${cc} ${base_name}.c -o ${base_name}').output) // compile
			// 	result := $if windows {
			// 		execute('${base_name}.exe')
			// 	} $else {
			// 		execute('${base_name}')
			// 	} // run
			// 	println(result.output)
			// }
			// 'clean', 'cl' {
			// 	rm(base_name) or {}
			// 	rm('${base_name}.exe') or {}
			// 	rm('${base_name}.c') or {}
			// 	println('Output files cleaned.')
			// }
			// 'clean_all', 'ca' {
			// 	mut result := execute('find . -name "*.c" -type f -delete')
			// 	println(result.output)
			// 	result = execute('find . -name "*.exe" -type f -delete')
			// 	println(result.output)
			// 	// result := execute('find . -name "*.c" -type f -delete')
			// 	// println(result.output)
			// }
			else {
				println('Invalid command.')
			}
		}
	}
}

fn help_message() string {
	return 'aixt is a tool for managing Aixt source code (*.aixt or *.v).

Usage:
  aixt command device input_file_name

Examples:
  aixt transpile pc hello.aixt	Transpile the file `hello.aixt` and output it as 
  								`hello.c`.
  aixt compile pc hello.aixt  	Compile a previously transpiled `hello.c` and 
								output it as `hello.hex` or equivalent binary file.
  aixt -c nxc hello.aixt      	Same as above, but make debugging easier
                            	(in case your program crashes).
  aixt crun hello.aixt         	Same as above, but do not recompile, if the
                            	executable already exists, and is newer than the
                            	sources.
  aixt -o h.c hello.aixt       	Translate `hello.aixt` to `h.c`. Do not compile
                            	further.
  aixt -o - hello.aixt         	Translate `hello.aixt` and output the C source code
                            	to stdout. Do not compile further.
  aixt watch hello.aixt        	Re-does the same compilation, when a source code
                            	change is detected.
                            	The program is only compiled, not run.
  aixt watch run hello.aixt    	Re-runs the same `hello.aixt` file, when a source
                            	code change is detected.

aixt supports the following commands:

  transpile, -t                Compile and run a V program. Delete the
                               executable after the run.
  compile, -c                  Compile and run a V program without deleting the
                               executable.
  run, -r                      Compile and run a V program without deleting the
                               executable.
  build, -b                    Compile and run a V program without deleting the
                               executable.
  clean, -cl                   Compile and run a V program without deleting the
                               executable.
  clean_all, -ca               Compile and run a V program without deleting the
                               executable.
  help, --help, -h             Compile and run a V program without deleting the
                               executable.'
}
