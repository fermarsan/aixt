// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
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
		setup.platform.value('cc_windows').string()
	} $else {
		setup.platform.value('cc_linux').string()
	}

	flags := setup.platform.value('cc_flags').string()
	output_flag := setup.platform.value('cc_output_flag').string()
	input_flag := setup.platform.value('cc_input_flag').string()

	input_ext := match setup.platform.value('backend').string() {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		else 		{ '.c' }
	}

	output_ext := match setup.platform.value('port').string() {
		'Emulator'	{
			$if windows { '.exe' } $else { '' }
		}
		else	{ '' }
	}
	// println('-------- ${os.dir(path)} --------')
	if os.exists('${os.dir(path)}/Makefile') {	// through Makefile
	println('make -f ${os.dir(path)}/Makefile')
		println(os.execute('make -f ${os.dir(path)}/Makefile PART=${setup.device}').output)
		// println(os.execute('make').output)
	} else {	// calling compiler directly
		mut command := '${cc} ${flags} '
		if os.is_dir(path) {
			command += if output_flag != '' {
				'${output_flag} ${path}/main${output_ext} '
			} else {
				''
			}
			command += '${input_flag} ${path}/main'
		} else {
			command += if output_flag != '' {
				'${output_flag} ${path}${output_ext} '
			} else {
				''
			}
			command += '${input_flag} ${path}${input_ext}'
		}
		println('${command}')
		println(os.execute('${command}').output)
	}
}