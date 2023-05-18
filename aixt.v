// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

import os
import toml
import aixtlib.builder
// import aixtlib.gen.cemb_gen
// import aixtlib.gen.nxc_gen

fn main() {
	aixt_path := os.dir(os.args[0])	// aixt base path

	command, device, input_name := os.args[1], os.args[2], os.args[3]	// capture arguments

	mut dev_setup_file := ''
	for setup_file in os.walk_ext('${aixt_path}/platforms/', 'toml') {	// find the device's setup file
		if setup_file.contains(os.norm_path('${device}/setup.toml')) {
			dev_setup_file = setup_file
			break
		}
	}
	setup := toml.parse_file(dev_setup_file) or { return }	// load the device's setup file


	// base_name	:= input_name.replace('.aixt', '')	// input file base name

	// C compiler depending on the OS
	cc := $if windows { setup.value('cc_windows').string() } $else { setup.value('cc_linux').string() }	

	match command {
		'transpile' {		
			file_list := os.walk_ext(os.dir(input_name), '.aixt')		// transpile secondary files
			for file in file_list { 
				if file != input_name {
					println(os.execute('v run ${aixt_builder} ${device} ${file}').output) 
				}
			}
			println(os.execute('v run ${aixt_builder} ${device} ${input_name}').output)	// transpile the main file
		}
		// 'compile' {	
		// 	// mut file_str_list := walk_ext(api_path, '.c').join(' ')
		// 	// println('file_str_list: ${file_str_list}')
		// 	// file_str_list += ' ' + walk_ext(dir(input_name), '.c').join(' ')
		// 	// println('file_str_list: ${file_str_list}')
		// 	// println(execute('${cc} ${file_str_list} -o ${base_name}').output)
		// 	println(execute('${cc} ${base_name}.c -o ${base_name}').output)
		// }
		// 'run' {
		// 	result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }
		// 	println(result.output)
		// }
		// 'build' {		
		// 	println( execute('${python} ${aixtt} ${input_name}').output )							// transpile
		// 	// compile_directory(api_path, cc)
		// 	println( execute('${cc} ${base_name}.c -o ${base_name}').output )					// compile
		// 	result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }	// run
		// 	println(result.output)
		// }
		// 'clean' {
		// 	rm(base_name) or {}
		// 	rm('${base_name}.exe') or {}
		// 	rm('${base_name}.c') or {}
		// 	println('Output files cleaned.')
		// }
		// 'clean_all' {
		// 	mut result := execute('find . -name "*.c" -type f -delete') 
		// 	println(result.output)
		// 	result = execute('find . -name "*.exe" -type f -delete') 
		// 	println(result.output)
		// 	// result := execute('find . -name "*.c" -type f -delete') 
		// 	// println(result.output)
		// }
		else {
			println('Invalid make option.')
		}
	}

	println(setup)
}