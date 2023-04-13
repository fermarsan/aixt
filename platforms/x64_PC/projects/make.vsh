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

$if windows {
	// println('Windows')
	match option {
		'transpile' {		
			result := execute('${settings.python_windows} ..\\..\\..\\aixtt.py ${input_name}')
			println(result.output)
		}
		'compile' {		
			basic_name := input_name.replace('.v', '')
			result := execute('${settings.cc_windows} ${basic_name}.c -o ${basic_name}')
			println(result.output)
		}
		'build' {		
			mut result := execute('${settings.python_windows} ..\\..\\..\\aixtt.py ${input_name}')
			println(result.output)
			basic_name := input_name.replace('.v', '')
			result = execute('${settings.cc_windows} ${basic_name}.c -o ${basic_name}')
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
			mut basic_name := input_name.replace('.v', '')
			basic_name = basic_name.replace('.aixt', '')
			basic_name = basic_name.replace('.aix', '')
			result := execute('${settings.cc_linux} ${basic_name}.c -o ${basic_name}')
			println(result.output)
		}
		'build' {		
			mut result := execute('${settings.python_linux} ../../../aixtt.py ${input_name}')
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
