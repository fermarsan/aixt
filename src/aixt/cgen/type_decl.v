// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// type_decl is the code generation function for type declaration
fn (mut gen Gen) type_decl(node ast.TypeDecl) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	// println(node)
	// match node {
	// 	ast.AliasTypeDecl {
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