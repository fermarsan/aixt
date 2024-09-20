// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_build

import os
import aixt_setup

// compile_file calls the port's defined compiler to compile a previous transpiled Aixt source code.
// example:
// ``` v
// aixt_build.compile_file('example.v', setup)
// ``` 
// Calls the compiler with `example.c` file, previously generated from `example.v` .
// If inside the containing folder of `example.v` a `Makefile`  exits, it calls the 
// `make`  command insted.
pub fn compile_file(path string, setup aixt_setup.Setup) {

	cc := $if windows { // C compiler depending on the OS
		setup.cc_windows
	} $else {
		setup.cc_linux
	}

	mut flags := setup.cc_make_flags
	flags = flags.replace('@{file_no_ext}', '${path}')	
	flags = flags.replace('@{file_dir_name}', '${os.dir(path)}')	
	flags = flags.replace('@{device}', '${setup.device}')

	input_ext := match setup.backend {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		else 		{ '.c' }
	}
	flags = flags.replace('@{input_ext}', '${input_ext}')

	output_ext := match setup.port {
		'Emulator'	{
			$if windows { '.exe' } $else { '' }
		}
		else	{ '' }
	}
	flags = flags.replace('@{output_ext}', '${output_ext}')	

	// println('-------- ${os.dir(path)} --------')
	if os.exists('${os.dir(path)}/Makefile') {		// calling compiler through Makefile
		println('make -f ${os.dir(path)}/Makefile ${flags}')
		println(os.execute('make -f ${os.dir(path)}/Makefile ${flags}').output)
	} else {
		println('${cc} ${flags}')
		println(os.execute('${cc} ${flags}').output)
	}
}