// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// for_c_stmt is the code generation function for the c-style 'for' statements.
fn (mut gen Gen) for_c_stmt(node ast.ForCStmt) string {
	mut out := 'for(${gen.ast_node(node.init)#[..-1]} ${gen.ast_node(node.cond)}; ${gen.ast_node(node.inc)#[..-2]}) {\n'
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	println('${out}')
	return out + '}\n'
}