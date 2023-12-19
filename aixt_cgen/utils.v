// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: utils.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation utils.
module aixt_cgen

import v.ast

fn (mut gen Gen) add_incl(name_ext string) {
	if !gen.includes.contains(name_ext) {
		gen.includes += '#include <${name_ext}>\n'
	}
}

fn (mut gen Gen) add_custom_incl(path_ext string) {
	if !gen.includes.contains(path_ext) {
		gen.includes += '#include "${path_ext}"\n'
	}
}