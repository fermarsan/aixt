// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// add_custom_include adds a include clause (non-standard) to the output file.
fn (mut gen Gen) add_custom_include(path_ext string) {
	if path_ext !in gen.includes {
		gen.includes << '#include "${path_ext}"\n'
	}
}