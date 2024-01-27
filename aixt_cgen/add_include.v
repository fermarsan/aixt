// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: add_include.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: add an include clause in the out file.
module aixt_cgen

fn (mut gen Gen) add_include(name_ext string) {
	if !gen.includes.contains(name_ext) {
		gen.includes += '#include <${name_ext}>\n'
	}
}