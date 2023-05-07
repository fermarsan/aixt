// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

import os
import json
import toml


equivalents := toml.parse_file('../api/equivalents.toml') or { panic('file does not exist. ') }

set_file := read_file('.vscode/settings.json')?	// read the settings file
settings := json.decode(Settings, set_file)?

option, input_name := os.args[1], os.args[2]	// capture arguments
	
base_name	:= input_name.replace('.aixt', '')	// input file base name

aixtt 		:= $if windows { settings.aixt_windows } $else { settings.aixt_linux }	// select tools according the OS
cc 			:= $if windows { settings.cc_windows } $else { settings.cc_linux }	
python 		:= $if windows { settings.python_windows } $else { settings.python_linux }  
// api_path 	:= $if windows { settings.api_windows } $else { settings.api_linux } 

match option {
	'transpile' {		
		file_list := walk_ext(dir(input_name), '.aixt')		// transpile secondary files
		for file in file_list { 
			if file != input_name {
				println(execute('${python} ${aixtt} ${file}').output) 
			}
		}
		println(execute('${python} ${aixtt} ${input_name}').output)	// transpile the main file
	}
	'compile' {	
		// mut file_str_list := walk_ext(api_path, '.c').join(' ')
		// println('file_str_list: ${file_str_list}')
		// file_str_list += ' ' + walk_ext(dir(input_name), '.c').join(' ')
		// println('file_str_list: ${file_str_list}')
		// println(execute('${cc} ${file_str_list} -o ${base_name}').output)
		println(execute('${cc} ${base_name}.c -o ${base_name}').output)
	}
	'run' {
		result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }
		println(result.output)
	}
	'build' {		
		println( execute('${python} ${aixtt} ${input_name}').output )							// transpile
		// compile_directory(api_path, cc)
		println( execute('${cc} ${base_name}.c -o ${base_name}').output )					// compile
		result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }	// run
		println(result.output)
	}
	'clean' {
		rm(base_name) or {}
		rm('${base_name}.exe') or {}
		rm('${base_name}.c') or {}
		println('Output files cleaned.')
	}
	'clean_all' {
		mut result := execute('find . -name "*.c" -type f -delete') 
		println(result.output)
		result = execute('find . -name "*.exe" -type f -delete') 
		println(result.output)
		// result := execute('find . -name "*.c" -type f -delete') 
		// println(result.output)
	}
	else {
		println('Invalid make option.')
	}
}

