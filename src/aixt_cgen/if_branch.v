// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// if_branch is the code generation function for 'if' branches.
fn (mut gen Gen) if_branch(node ast.IfBranch) string { // statements block of "if" and "else" expressions
	mut out := ''
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	return out
}