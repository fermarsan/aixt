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

// read the settings file
set_file := read_file('projects/.vscode/settings.json')?
settings := json.decode(Settings, set_file)?

println(settings)

// for arg in os.args {
//     println("arg: ${arg}")
// }

// if os.args[1] == 'Transpile' {
// 	result := execute('python3 ../../')

// }