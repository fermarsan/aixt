// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module main

import os
import aixt.setup

// c_compile calls the port's defined compiler to compile a previous transpiled Aixt source code.
// example:
// ``` v
// build.compile_file('example.v', project_setup)
// ``` 
// Calls the compiler with `example.c` file, previously generated from `example.v` .
// If inside the containing folder of `example.v` a `Makefile`  exits, it calls the 
// `make`  command instead.
pub fn c_compile(path string, project_setup setup.Setup) {

	cc := $if windows { // C compiler depending on the OS
		project_setup.cc_windows
	} $else {
		project_setup.cc_linux
	}

	mut flags := project_setup.cc_make_flags
	flags = flags.replace('@{file_no_ext}', '${path}')	
	flags = flags.replace('@{file_dir_name}', '${os.dir(path)}')	
	flags = flags.replace('@{device}', '${project_setup.device}')

	input_ext := match project_setup.backend {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		else 		{ '.c' }
	}
	flags = flags.replace('@{input_ext}', '${input_ext}')

	output_ext := match project_setup.port {
		'Emulator'	{
			$if windows { '.exe' } $else { '' }
		}
		else	{ '' }
	}
	flags = flags.replace('@{output_ext}', '${output_ext}')	

	// println('-------- ${os.dir(path)} --------')
	if os.exists('${os.dir(path)}' + os.path_separator + 'Makefile') {		// calling compiler through Makefile
		println('make -f ${os.dir(path)}' + os.path_separator + 'Makefile ${flags}')
		println(os.execute('make -f ${os.dir(path)}' + os.path_separator + 'Makefile ${flags}').output)
	} else {
		println('${cc} ${flags}')
		println(os.execute('${cc} ${flags}').output)
	}
}