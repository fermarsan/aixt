// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

import os
import json


struct Settings {
    cc_linux		string
	cc_windows		string
    python_linux	string
    python_windows	string
}
set_file := read_file('.vscode/settings.json')?	// read the settings file
settings := json.decode(Settings, set_file)?

option, input_name := os.args[1], os.args[2]	// capture arguments
mut result := ''								// result for the commands

$if windows {
	println('Windows')
}
$else {
	// println('Linux')
	match option {
		'transpile' {		
			result = execute('${settings.python_linux} ../../../aixtt.py ${input_name}')
			println(result.output)
		}
		'compile' {		
			basic_name := input_name.replace('.v', '')
			result = execute('${settings.cc_linux} ${basic_name}.c -o ${basic_name}')
			println(result.output)
		}
		'build' {		
			result = execute('${settings.python_linux} ../../../aixtt.py ${input_name}')
			println(result.output)
			basic_name := input_name.replace('.v', '')
			result = execute('${settings.cc_linux} ${basic_name}.c -o ${basic_name}')
			println(result.output)
		}
		else {
			println('invalid option.')
		}
	}
}
