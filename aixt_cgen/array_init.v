// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// array_init is the code generation function for arrays initialization.
fn (mut gen Gen) array_init(node ast.ArrayInit) string {
	mut out := '{'
	for ex in node.exprs {
		out += '${gen.ast_node(ex)}, '
	}
	out = out#[..-2]
	return out + '}'
}