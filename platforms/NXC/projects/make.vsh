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

cc := $if windows { settings.cc_windows } $else { settings.cc_linux }	// select tools according the OS
python := $if windows { settings.python_windows } $else { settings.python_linux }  
aixtt := $if windows { '..\\..\\..\\aixtt.py' } $else { '../../../aixtt.py' }

match option {
	'transpile' {
		result := execute('${python} ${aixtt} ${input_name} -nxc')
		println(result.output)
	}
	'compile' {	
		result := execute('${cc} ${base_name}.nxc -T=NXT -S=usb -d')
		println(result.output)
	}
	'build' {		
		mut result := execute('${python} ${aixtt} ${input_name} -nxc')
		println(result.output)
		result = execute('${cc} ${base_name}.nxc -T=NXT -S=usb -d')
		println(result.output)
	}
	'clean' {
		rm('${base_name}.nxc') or {}
		println('Output file cleaned.')
	}
	'clean_all' {
		result := execute('find . -name "*.ncx" -type f -delete') 
		println(result.output)
	}
	else {
		println('invalid option.')
	}
}