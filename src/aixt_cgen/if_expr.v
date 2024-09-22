// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// if_expr is the code generation function for 'if' expressions.
fn (mut gen Gen) if_expr(node ast.IfExpr) []string { // basic shape of an "if" expression
	mut out := []string{}
	mut cond := gen.ast_node(node.branches[0].cond).join('')
	if node.is_comptime {
		out = gen.if_expr_comptime(node)
	} else {
		if node.is_expr { // in case of conditional assignment
			out << 'if(${cond}) {'
			out << gen.single_assign(	gen.cur_left, 
										gen.cur_left_type, 
										gen.cur_op, 
										(node.branches[0].stmts[0] as ast.ExprStmt).expr	)
			out << '}'
			for i, br in node.branches {
				if i >= 1 {
					out << 'else '
					if br.cond.type_name().str() == 'unknown v.ast.Expr' { // only 'else'
						out << '{'
						out << gen.single_assign(	gen.cur_left, 
													gen.cur_left_type, 
													gen.cur_op, 
													(br.stmts[0] as ast.ExprStmt).expr	)
					} else {	//'else if'
						out << 'if(${gen.ast_node(br.cond).join('')}) {'
						out << gen.single_assign(	gen.cur_left, 
													gen.cur_left_type, 
													gen.cur_op, 
													(br.stmts[0] as ast.ExprStmt).expr	) 
					}
					out << '}'
				}
			}
		} else {
			mut stmts := gen.ast_node(node.branches[0])
			out << $tmpl('c_templates/if_block.c')#[..-1]
			for i, br in node.branches {
				if i >= 1 {
					if br.cond.type_name().str() == 'unknown v.ast.Expr' { // only 'else'
						stmts = gen.ast_node(br)
						out << $tmpl('c_templates/else_block.c')#[..-1]
					} else {	//'else if'
						cond = gen.ast_node(br.cond).join('')
						stmts = gen.ast_node(br)
						out << $tmpl('c_templates/else_if_block.c')#[..-1]
					}
				}
			}
		}
	}
	return out
}