// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: if.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for 'if' expressions and branches.
module aixt_cgen

import v.ast

fn (mut gen Gen) if_expr(node ast.IfExpr) string { // basic shape of an "if" expression
	mut out := 'if(${gen.ast_node(node.branches[0].cond)}) {\n${gen.ast_node(node.branches[0])}}\n'
	for i, br in node.branches {
		if i >= 1 {
			out += 'else '
			if br.cond.type_name().str() == 'unknown v.ast.Expr' { // only 'else'
				out += '{\n${gen.ast_node(br)}}\n'
			} else {
				out += 'if(${gen.ast_node(br.cond)}) {\n${gen.ast_node(br)}}\n' //'else if'
			}
		}
	}
	return out
}

fn (mut gen Gen) if_branch(node ast.IfBranch) string { // statements block of "if" and "else" expressions
	mut out := ''
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	return out
}