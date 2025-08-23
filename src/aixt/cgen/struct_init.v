// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// struct_init is the code generation function for struct initialization
fn (mut gen Gen) struct_init(node ast.StructInit) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	match node.language {
		.v {
			name := '__struct_name__'
			mut fields := []string{}
			for field in node.init_fields {
				fields << gen.ast_node(field)
			}
			out << $tmpl('c_templates/struct_init.tmpl.c')
		}
		else {
			out = ['']
		}
	}
	return out
}