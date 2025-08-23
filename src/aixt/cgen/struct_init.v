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
	// match node.language {
	// 	.v {
	// 		attrs := node.attrs.map(it.name).join(' ')
	// 		name := node.name.replace('.', '__')
	// 		mut fields := []string{}
	// 		for field in node.fields {
	// 			fields << gen.ast_node(field)
	// 		}
	// 		out << $tmpl('c_templates/struct.tmpl.c')
	// 	}
	// 	else {
	// 		out = ['']
	// 	}
	// }
	return out
}