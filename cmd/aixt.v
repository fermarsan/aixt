// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

import os
// import json
import toml

// println(os.getwd())

// equivalents := toml.parse_file('../api/equivalents.toml') or { panic('file does not exist. ') }

// set_file := read_file('.vscode/settings.json')!	// read the settings file
// settings := json.decode(Settings, set_file)!
setup := toml.parse_file('../setup.toml') or { panic(err) }

option, input_name := os.args[1], os.args[2]	// capture arguments
	
base_name	:= input_name.replace('.aixt', '')	// input file base name

cc := $if windows { setup.value('cc_windows').string() } $else { setup.value('cc_linux').string() }	

aixt_api := setup.value('aixt_api').string()
$if windows { aixt_api = aixt_api.replace('/', '\\') }

aixt_builder := setup.value('aixt_builder').string()
$if windows { aixt_builder = aixt_builder.replace('/', '\\') }

match option {
	'transpile' {		
		file_list := os.walk_ext(os.dir(input_name), '.aixt')		// transpile secondary files
		for file in file_list { 
			if file != input_name {
				println(os.execute('v run ${aixt_builder} ${file}').output) 
			}
		}
		println(os.execute('v run ${aixt_builder} ${input_name}').output)	// transpile the main file
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

