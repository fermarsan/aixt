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
// calls the compiler with `example.c` previously generated from `example.v`
pub fn compile_file(path string, setup_file toml.Doc) {

	cc := $if windows { // C compiler depending on the OS
		setup_file.value('cc_windows').string()
	} $else {
		setup_file.value('cc_linux').string()
	}

	flags := setup_file.value('cc_flags').string()

	// compiles the output file
	if setup_file.value('backend').string() == 'nxc' {
		println(os.execute('${cc} ${path}.nxc ${flags} ${path}').output)
	} else { 
		println(os.execute('${cc} ${path}.c ${flags} ${path}').output)
	}
}
