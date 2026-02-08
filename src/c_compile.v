// Author: Fernando M. Santa
// Date: 2023-2025

module main

import os
import aixt.setup

// c_compile calls the port's defined compiler to compile a previously transpiled Aixt source code.
// example:
// ``` v
// c_compile('example.v', '~/nbc/nbc', '-T:NXT', project_setup)
// ```
// Calls the `nbc` compiler with `example.c` file, previously generated from `example.v` .
// If inside the containing folder of `example.v` a `Makefile`  exits, it calls the
// `make`  command instead.
pub fn c_compile(path string, cc_path string, cc_args string, project_setup setup.Setup) {

	mut args := cc_args
	args = args.replace('@{file_no_ext}', '${path}')
	args = args.replace('@{file_dir_name}', '${os.dir(path)}')
	args = args.replace('@{device}', '${project_setup.device}')

	input_ext := match project_setup.backend {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' }
		else 		{ '.c' }
	}
	args = args.replace('@{input_ext}', '${input_ext}')

	output_ext := match project_setup.target {
		'Emulator'	{
			$if windows { '.exe' } $else { '' }
		}
		else	{ '' }
	}
	args = args.replace('@{output_ext}', '${output_ext}')

	// println('-------- ${os.dir(path)} --------')
	if os.exists(os.norm_path('${os.dir(path)}/Makefile')) {		// calling compiler through Makefile
		println(os.norm_path('make -f ${os.dir(path)}/Makefile ${args}'))
		println(os.execute(os.norm_path('make -f ${os.dir(path)}/Makefile ${args}')).output)
	} else {
		println(os.norm_path('${cc_path} ${args}'))
		println(os.execute(os.norm_path('${cc_path} ${args}')).output)
	}
}
