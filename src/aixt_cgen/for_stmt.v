// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// for_stmt is the code generation function for the bare 'for' statement.
fn (mut gen Gen) for_stmt(node ast.ForStmt) []string {
	mut out := ['while(']
	out << if node.is_inf { 'true) {' } else { '${gen.ast_node(node.cond).join('')}) {' }
	for st in node.stmts {
		out << gen.ast_node(st)
	}
	out << '}'
	return out
}