// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// global_decl is the code generation function for global declarations.
fn (mut gen Gen) global_decl(node ast.GlobalDecl) string {
	mut out := ''
	for f in node.fields {
		out += '\n${gen.ast_node(f)}'
	}
	gen.definitions << out
	return ''
}