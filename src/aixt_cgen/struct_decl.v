// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// struct_decl is the code generation function for struct declaration
fn (mut gen Gen) struct_decl(node ast.StructDecl) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	match node.language {
		.v {
			attrs := node.attrs.map(it.name).join(' ')
			name := node.name.replace('.', '__')
			mut fields := []string{}
			for field in node.fields {
				fields << gen.ast_node(field)
			}
			out << $tmpl('c_templates/struct.tmpl.c')
		}
		else {
			out = ['']
		}
	}
	return out
}