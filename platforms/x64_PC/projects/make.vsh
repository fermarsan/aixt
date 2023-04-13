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

mut base_name := input_name.replace('.v', '')	// input file base name	
base_name = base_name.replace('.aixt', '')
base_name = base_name.replace('.aix', '')

$if windows {
	// println('Windows')
	match option {
		'transpile' {		
			result := execute('${settings.python_windows} ..\\..\\..\\aixtt.py ${input_name}')
			println(result.output)
		}
		'compile' {		
			result := execute('${settings.cc_windows} ${base_name}.c -o ${base_name}')
			println(result.output)
		}
		'build' {		
			mut result := execute('${settings.python_windows} ..\\..\\..\\aixtt.py ${input_name}')
			println(result.output)
			result = execute('${settings.cc_windows} ${base_name}.c -o ${base_name}')
			println(result.output)
		}
		else {
			println('invalid option.')
		}
	}
}
$else {
	// println('Linux')
	match option {
		'transpile' {		
			result := execute('${settings.python_linux} ../../../aixtt.py ${input_name}')
			println(result.output)
		}
		'compile' {		
			result := execute('${settings.cc_linux} ${base_name}.c -o ${base_name}')
			println(result.output)
		}
		'build' {		
			mut result := execute('${settings.python_linux} ../../../aixtt.py ${input_name}')
			println(result.output)
			result = execute('${settings.cc_linux} ${base_name}.c -o ${base_name}')
			println(result.output)
		}
		else {
			println('invalid option.')
		}
	}
}
