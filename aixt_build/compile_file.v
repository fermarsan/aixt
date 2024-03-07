// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_build

import os
import toml

// compile_file calls the port's defined compiler to compile a previous transpiled Aixt source code.
// example:
// ```v
// aixt_build.compile_file('example.v', setup)
// ```
// Calls the compiler with `example.c` file, previously generated from `example.v`.
// If inside the containing folder of `example.v` a `Makefile` exits, it calls the 
// `make` command insted.
pub fn compile_file(path string, setup_file toml.Doc) {

	cc := $if windows { // C compiler depending on the OS
		setup_file.value('cc_windows').string()
	} $else {
		setup_file.value('cc_linux').string()
	}

	flags := setup_file.value('cc_flags').string()

	input_ext := match setup_file.value('backend').string() {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		else 		{ '.c' }
	}

	output_ext := match setup_file.value('port').string() {
		'Emulator'	{
			$if windows { '.exe' } $else { '' }
		}
		else 		{ '' }
	}

	if os.exists('${path.all_before_last('/')}/Makefile') {	// through Makefile
		// println('Makefile OK')
		println(os.execute('make -C ${path.all_before_last('/')}').output)
	} else {	// calling compiler directly
		if os.is_dir(path) {
			println(os.execute('${cc} ${path}/main${input_ext} ${flags} ${path}/main').output)
		} else {
			println(os.execute('${cc} ${path}${input_ext} ${flags} ${path}${output_ext}').output)
		}
	}
}