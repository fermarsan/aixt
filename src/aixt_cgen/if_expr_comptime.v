// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// if_expr_comptime is the code generation function for compilation time 'if' expressions.
fn (mut gen Gen) if_expr_comptime(node ast.IfExpr) []string { // basic shape of an "if" expression
	mut out := []string{}

	if node.is_expr { // in case of conditional assignment
		for i, br in node.branches {
			if br.stmts.len > 0 { 
				out << if br.cond.str().contains('[') {
					'// not ${node.branches[i-1].cond.str().replace('?', '')}'	
				} else {
					'// ${br.cond.str().replace('?', '')}'
				}
				out << gen.single_assign(	gen.cur_left, 
											gen.cur_left_type, 
											gen.cur_op, 
											(br.stmts[0] as ast.ExprStmt).expr	)
			}
		}
	} else {
		// println('?????????????????????????? ${node} ???????????????????????')
		for i, br in node.branches {
			if br.stmts.len > 0 {
				out << if br.cond.str().contains('[') {
					'// not ${node.branches[i-1].cond.str().replace('?', '')}'	
				} else {
					'// ${br.cond.str().replace('?', '')}'
				}
				out << gen.ast_node(br)
			}
		}
	}
	return out
}

