// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: for_c_stmt.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for all variations of the 'for' c-style statement.
module aixt_cgen

import v.ast

fn (mut gen Gen) for_c_stmt(node ast.ForCStmt) string {
	mut out := 'for(${gen.ast_node(node.init)#[..-1]} ${gen.ast_node(node.cond)}; ${gen.ast_node(node.inc)#[..-2]}) {\n'
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	println('${out}')
	return out + '}\n'
}