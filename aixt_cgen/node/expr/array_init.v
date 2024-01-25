// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: array_init.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for array initialization.
module aixt_cgen

import v.ast
fn (mut gen Gen) array_init(node ast.ArrayInit) string {
	mut out := '{'
	for ex in node.exprs {
		out += '${gen.ast_node(ex)}, '
	}
	out = out#[..-2]
	return out + '}'
}