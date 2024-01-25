// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: add_custom_include.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: add a custom include clause in the out file.
module aixt_cgen

fn (mut gen Gen) add_custom_include(path_ext string) {
	if !gen.includes.contains(path_ext) {
		gen.includes += '#include "${path_ext}"\n'
	}
}