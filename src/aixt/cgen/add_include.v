// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

// add_include adds an include clause to the output file.
fn (mut gen Gen) add_include(name_plus_ext string) {
	// println('gen.c_preproc_cmds = ${gen.c_preproc_cmds}')
	if '#include <${name_plus_ext}>' !in gen.c_preproc_cmds {
		gen.c_preproc_cmds << '#include <${name_plus_ext}>'
	}
}


// add_custom_include adds a include clause (non-standard) to the output file.
fn (mut gen Gen) add_custom_include(path_plus_ext string) {
	if '#include "${path_plus_ext}"' !in gen.c_preproc_cmds {
		gen.c_preproc_cmds << '#include "${path_plus_ext}"'
	}
}