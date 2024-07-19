// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// if_expr is the code generation function for 'if' expressions.
fn (mut gen Gen) if_expr(node ast.IfExpr) []string { // basic shape of an "if" expression
	mut out := []string{}
	if node.is_comptime {	// in case of compilation time
		// println('------------------------ ${node.branches[0].cond.str()} ---------------------------')
		match node.branches[0].cond.str() {
			'linux'
		}
		// if node.branches[0].cond
		// out << 'if(${gen.ast_node(node.branches[0].cond).join('')}) {'
	} else if node.is_expr { // in case of conditional assignment
		out << '(${gen.ast_node(node.branches[0].cond).join('')}) ? ${node.branches[0].stmts[0]} : ${node.branches[1].stmts[0]}'
	} else {
		out << 'if(${gen.ast_node(node.branches[0].cond).join('')}) {'
		out << gen.ast_node(node.branches[0])
		out << '}'
		for i, br in node.branches {
			if i >= 1 {
				out << 'else '
				if br.cond.type_name().str() == 'unknown v.ast.Expr' { // only 'else'
					out << '{'
					out << gen.ast_node(br)
					out << '}'
				} else {	//'else if'
					out << 'if(${gen.ast_node(br.cond).join('')}) {'
					out << gen.ast_node(br)
					out << '}' 
				}
			}
		}
	}
	return out
}