// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// Governed by an MIT license (MIT)
// Copyright (c) 2023 Fernando Martínez Santa

import os
import toml
// import v.ast
// import v.parser
// import v.pref
// import cgen
import pref
// import lib.builder
// import v.builder // CHECK



fn main() {
	aixt_path := os.dir(os.args[0])	// aixt base path
	command := os.args[1]	// command

	if command in ['help', '--help', '-h'] {
		help_message()
	} else {
		device, backend, input_name := os.args[2], os.args[3], os.args[4]	// capture arguments

		dev_setup_file := '${aixt_path}/devices/${pref.device_path(device)}/setup.toml'
		setup := toml.parse_file(dev_setup_file) or { return }	// load the device's setup file
		println(setup)

	}

	

	// base_name	:= input_name.replace('.aixt', '')	// input file base name

	// // C compiler depending on the OS
	// cc := $if windows { setup.value('cc_windows').string() } $else { setup.value('cc_linux').string() }	

	// mut vpref := &pref.Preferences{}
	// vpref.is_script = true	// enable script mode
	// table := ast.new_table()	
	// // ---------- Parsing ----------
	// mut parsed := parser.parse_file(path, table, .skip_comments, vpref)
	// mut checker_ := checker.new_checker(table, vpref)
	// checker_.check(parsed)

	// match command {
	// 	'transpile' {		
	// 		// builder.build_api(aixt_path)
	// 		transpiled := aixt_gen.cgen(parsed, table, vpref)	// transpile the main file
	// 		println('\n\n${transpiled}\n\n')
	// 	}
	// 	// 'compile' {	
	// 	// 	// mut file_str_list := walk_ext(api_path, '.c').join(' ')
	// 	// 	// println('file_str_list: ${file_str_list}')
	// 	// 	// file_str_list += ' ' + walk_ext(dir(input_name), '.c').join(' ')
	// 	// 	// println('file_str_list: ${file_str_list}')
	// 	// 	// println(execute('${cc} ${file_str_list} -o ${base_name}').output)
	// 	// 	println(execute('${cc} ${base_name}.c -o ${base_name}').output)
	// 	// }
	// 	// 'run' {
	// 	// 	result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }
	// 	// 	println(result.output)
	// 	// }
	// 	// 'build' {		
	// 	// 	println( execute('${python} ${aixtt} ${input_name}').output )							// transpile
	// 	// 	// compile_directory(api_path, cc)
	// 	// 	println( execute('${cc} ${base_name}.c -o ${base_name}').output )					// compile
	// 	// 	result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }	// run
	// 	// 	println(result.output)
	// 	// }
	// 	// 'clean' {
	// 	// 	rm(base_name) or {}
	// 	// 	rm('${base_name}.exe') or {}
	// 	// 	rm('${base_name}.c') or {}
	// 	// 	println('Output files cleaned.')
	// 	// }
	// 	// 'clean_all' {
	// 	// 	mut result := execute('find . -name "*.c" -type f -delete') 
	// 	// 	println(result.output)
	// 	// 	result = execute('find . -name "*.exe" -type f -delete') 
	// 	// 	println(result.output)
	// 	// 	// result := execute('find . -name "*.c" -type f -delete') 
	// 	// 	// println(result.output)
	// 	// }
	// 	else {
	// 		println('Invalid make option.')
	// 	}
	// }

	
}

fn help_message() string{

	return 'aixt is a tool for managing Aixt source code (*.aixt or *.v).

Usage:
  aixt command device backend input_file_name

Examples:
  aixt hello.aixt					Compile the file `hello.aixt` and output it as
                            	`hello` or `hello.exe`.
  aixt run hello.aixt          	Same as above but also run the produced
                        		executable immediately after compilation.
  aixt -cg run hello.aixt      	Same as above, but make debugging easier
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

V supports the following commands:

* Project Scaffolding Utilities:
  new                          Setup the file structure for a V project
                               (in a sub folder).
  init                         Setup the file structure for an already existing
                               V project.

* Commonly Used Utilities:
  run                          Compile and run a V program. Delete the
                               executable after the run.
  crun                         Compile and run a V program without deleting the
                               executable.
                               If you run the same program a second time,
                               without changing the source files,
                               V will just run the executable, without
                               recompilation. Suitable for scripting.
  test                         Run all test files in the provided directory.
  fmt                          Format the V code provided.
  vet                          Report suspicious code constructs.
  doc                          Generate the documentation for a V module.
  vlib-docs                    Generate and open the documentation of all the
                               vlib modules.
  repl                         Run the REPL.
  watch                        Re-compile/re-run a source file, each time it is
                               changed.
  where                        Find and print the location of current project
                               declarations.

* Installation Management Utilities:
  symlink                      Create a symbolic link for V.
  up                           Run the V self-updater.
  self [-prod]                 Run the V self-compiler, use -prod to optimize
                               compilation.
  version                      Print the version text and exits.

* Package Management Utilities:
  install                      Install a module from VPM.
  remove                       Remove a module that was installed from VPM.
  search                       Search for a module from VPM.
  update                       Update an installed module from VPM.
  upgrade                      Upgrade all the outdated modules.
  list                         List all installed modules.
  outdated                     List installed modules that need updates.
  show                         Display information about a module on vpm'
}

