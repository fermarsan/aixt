// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: if_branch.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for 'if' branches.
module aixt_cgen

import v.ast

fn (mut gen Gen) if_branch(node ast.IfBranch) string { // statements block of "if" and "else" expressions
	mut out := ''
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	return out
}