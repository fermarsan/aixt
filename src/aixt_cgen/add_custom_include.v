// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// add_custom_include adds a include clause (non-standard) to the output file.
fn (mut gen Gen) add_custom_include(path_plus_ext string) {
	if '#include "${path_plus_ext}"' !in gen.c_preproc_cmds {
		gen.c_preproc_cmds << '#include "${path_plus_ext}"'
	}
}