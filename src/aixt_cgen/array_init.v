// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// array_init is the code generation function for arrays initialization.
fn (mut gen Gen) array_init(node ast.ArrayInit) []string {
	// println('================== ${node} ==================')
	// println("+++++++++++++++\n${node}\n+++++++++++++++")
	mut c_line := '{'
	if node.exprs.len != 0 {
		for ex in node.exprs {
			c_line += '${gen.ast_node(ex).join('')}, '
		}
		c_line = c_line#[..-2] + '}'
	}
	// println("+++++++++++++++\n${c_line}\n+++++++++++++++")
	return [c_line]
}