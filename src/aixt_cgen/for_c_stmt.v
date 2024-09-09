// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// for_c_stmt is the code generation function for the c-style 'for' statements.
fn (mut gen Gen) for_c_stmt(node ast.ForCStmt) []string {
	mut for_header := 'for(${gen.ast_node(node.init).join('')}'
	for_header += ' ${gen.ast_node(node.cond).join('')};'
	for_header += ' ${gen.ast_node(node.inc).join('')#[..-1]}) {'
	mut out := [for_header]
	for st in node.stmts {
		out << gen.ast_node(st)
	}
	// println('${out}')
	out << '}'
	return out
}