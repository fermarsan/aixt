// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: compile_file.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: Function for compiling a previous transpiled Aixt source code.

module aixt_build

import os
import toml

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
