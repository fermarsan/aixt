// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

import os
import json

struct Settings {
	aixt_linux   	string
	aixt_windows  	string
	cc_linux      	string
	cc_windows    	string
	python_linux  	string
	python_windows	string
	api_linux     	string
	api_windows   	string
}

set_file := read_file('.vscode/settings.json')?	// read the settings file
settings := json.decode(Settings, set_file)?

option, input_name := os.args[1], os.args[2]	// capture arguments

mut base_name := input_name.replace('.v', '')	// input file base name	
base_name = base_name.replace('.aixt', '')
base_name = base_name.replace('.aix', '')

aixtt 		:= $if windows { settings.aixt_windows } $else { settings.aixt_linux }	// select tools according the OS
cc 			:= $if windows { settings.cc_windows } $else { settings.cc_linux }	
python 		:= $if windows { settings.python_windows } $else { settings.python_linux }  
api_path 	:= $if windows { settings.api_windows } $else { settings.api_linux } 

match option {
	'transpile' {
		println( execute('${python} ${aixtt} ${input_name}').output )
	}
	'compile' {	
		result := execute('${cc} ${base_name}.c -o ${base_name}')
		println(result.output)
	}
	'run' {
		result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }
		println(result.output)
	}
	'build' {		
		mut result := execute('${python} ${aixtt} ${input_name}')
		println(result.output)
		result = execute('${cc} ${base_name}.c -o ${base_name}')
		println(result.output)
		result = $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }
		println(result.output)
	}
	'clean' {
		rm(base_name) or {}
		rm('${base_name}.exe') or {}
		rm('${base_name}.c') or {}
		println('Files cleaned.')
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
		println('invalid option.')
	}
}