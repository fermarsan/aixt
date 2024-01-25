// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: global_decl.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for global declarations.
module aixt_cgen

import v.ast

fn (mut gen Gen) global_decl(node ast.GlobalDecl) string {
	mut out := ''
	for f in node.fields {
		out += '${gen.ast_node(f)}'
	}
	return out
}