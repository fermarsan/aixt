// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// add_include adds an include clause to the output file.
fn (mut gen Gen) add_include(name_ext string) {
	if name_ext !in gen.c_preproc_cmds {
		gen.c_preproc_cmds << '#include <${name_ext}>\n'
	}
}