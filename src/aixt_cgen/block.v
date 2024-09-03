// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// block is the code generation function for blocks.
fn (mut gen Gen) block(node ast.Block) []string {
	mut out := []string{}
	out << '{'
	for st in node.stmts {
		out << gen.ast_node(st)
		out << '\n'
	}
	out << '}'
	return out
}