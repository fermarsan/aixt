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

println( ls(getwd())? )
println( ls(getwd())? )

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

println( ls(getwd())? )
println( ls(dir(api_path))? )

match option {
	'transpile' {
		println( execute('${python} ${aixtt} ${input_name}').output )
	}
	'compile' {	
		println( execute('${cc} ${base_name}.c -o ${base_name}').output )
	}
	'run' {
		result := $if windows { execute('${base_name}.exe') } $else { execute('${base_name}') }
		println(result.output)
	}
	'build' {		
		println( execute('${python} ${aixtt} ${input_name}').output )							// transpile
		println( execute('${cc} ${base_name}.c -o ${base_name}').output )						// compile
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