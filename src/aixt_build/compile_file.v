// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_build

import os
import aixt_setup

// compile_file calls the port's defined compiler to compile a previous transpiled Aixt source code.
// example:
// ```v
// aixt_build.compile_file('example.v', setup)
// ```
// Calls the compiler with `example.c` file, previously generated from `example.v`.
// If inside the containing folder of `example.v` a `Makefile` exits, it calls the 
// `make` command insted.
pub fn compile_file(path string, setup aixt_setup.Setup) {

	cc := $if windows { // C compiler depending on the OS
		setup.cc_windows
	} $else {
		setup.cc_linux
	}

	mut flags := if os.exists('${os.dir(path)}/Makefile') {
		setup.makefile_flags
	} else {
		setup.cc_flags
	}

	flags.replace('@{file_no_extension}', '${path}')	
	flags.replace('@{file_dir_name}', '${os.dir(path)}')	
	flags.replace('@{device}', '${setup.device}')

	input_ext := match setup.backend {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		else 		{ '.c' }
	}
	flags.replace('@{input_extension}', '${input_ext}')
	
	output_ext := match setup.port {
		'Emulator'	{
			$if windows { '.exe' } $else { '' }
		}
		else	{ '' }
	}
	flags.replace('@{output_extension}', '${output_ext}')	

	// println('-------- ${os.dir(path)} --------')
	if os.exists('${os.dir(path)}/Makefile') {		// calling compiler through Makefile
		mut flags := setup.makefile_flags
		println('make -f ${os.dir(path)}/Makefile ${flags}')
		println(os.execute('make -f ${os.dir(path)}/Makefile ${flags}').output)
	} else {	
		mut flags := setup.cc_flags								// calling compiler directly
		mut command := '${cc} ${flags} '

		command += if output_flag != '' {
			'${output_flag} ${path}${output_ext} '
		} else {
			''
		}

		command += '${input_flag} ${path}${input_ext}'

		command -= match setup.backend {
			'nxc' 		{ '.nxc' }
			'arduino'	{ '.ino' } 
			else 		{ '.c' }
		}

		println('${command}')
		println(os.execute('${command}').output)
	}
}