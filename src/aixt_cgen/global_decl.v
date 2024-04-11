// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// global_decl is the code generation function for global declarations.
fn (mut gen Gen) global_decl(node ast.GlobalDecl) string {
	// println('+++++++++++++++\n${node}\n+++++++++++++++')
	mut out := ''
	for f in node.fields {
		// out += '\n${gen.ast_node(f)}'
		out += if node.attrs.len != 0 && node.attrs[0].name == 'mutex' {
			'mutex ${f.name};\n'		// for NXC backend
		} else {
			'\n${gen.ast_node(f)}'
		}
	}
	gen.definitions << out
	return ''
}