// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module cgen

import v.ast
import v.token

// if_expr is the code generation function for 'if' expressions.
fn (mut gen Gen) if_expr(node ast.IfExpr) []string { // basic shape of an "if" expression
	mut out := []string{}
	mut cond := gen.ast_node(node.branches[0].cond).join('')
	mut stmts := []string{}
	if node.is_comptime {
		out = gen.if_expr_comptime(node)
	} else {
		if node.is_expr { // in case of conditional assignment
			// println('>>>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<<<')
			if gen.cur_op.str() == ':=' {	// in case of declaration/assignment
				// first declare
				out << gen.single_decl_assign(	gen.cur_left, 
												gen.cur_left_type, 
												ast.EmptyExpr(0)	)	// only declaration if empty right value
				// then assign
				stmts = gen.single_assign(	gen.cur_left, 
											gen.cur_left_type, 
											token.Kind.assign,	// only assignment '='
											(node.branches[0].stmts[0] as ast.ExprStmt).expr	)
			} else {
				stmts = gen.single_assign(	gen.cur_left, 
											gen.cur_left_type, 
											gen.cur_op, 
											(node.branches[0].stmts[0] as ast.ExprStmt).expr	)
			}
			out << $tmpl('c_templates/if_block.tmpl.c')#[..-1]	
			// println('>>>>>>>>>>>>>>>>>>>> ${out} <<<<<<<<<<<<<<<<<<<<')						
			for i, br in node.branches {
				if i >= 1 {
					// println('>>>>>>>>>>>>>>>>>>>> ${br.cond.type_name().str()} <<<<<<<<<<<<<<<<<<<<')	
					if br.cond.type_name().str() == 'v.ast.NodeError' { // only 'else'
						stmts = gen.single_assign(	gen.cur_left, 
													gen.cur_left_type, 
													if gen.cur_op.str() == ':=' { token.Kind.assign } else { gen.cur_op },
													(br.stmts[0] as ast.ExprStmt).expr	)
						// if gen.cur_op.str() == ':=' {	// in case of declaration/assignment
						// 	stmts = gen.single_assign(	en.cur_left, 
						// 								gen.cur_left_type, 
						// 								token.Kind.assign,	// only assignment '='
						// 								(br.stmts[0] as ast.ExprStmt).expr	)
						// } else {
						// 	stmts = gen.single_assign(	gen.cur_left, 
						// 								gen.cur_left_type, 
						// 								gen.cur_op, 
						// 								(br.stmts[0] as ast.ExprStmt).expr	)
						// }
						out << $tmpl('c_templates/else_block.tmpl.c')#[..-1]
					} else {	//'else if'
						cond = gen.ast_node(br.cond).join('')
						stmts = gen.single_assign(	gen.cur_left, 
													gen.cur_left_type, 
													if gen.cur_op.str() == ':=' { token.Kind.assign } else { gen.cur_op },
													(br.stmts[0] as ast.ExprStmt).expr	) 
						out << $tmpl('c_templates/else_if_block.tmpl.c')#[..-1]
					}
				}
			}
		} else {
			stmts = gen.ast_node(node.branches[0])
			out << $tmpl('c_templates/if_block.tmpl.c')#[..-1]
			for i, br in node.branches {
				// println('branch ${i}:\n${br}')
				if i >= 1 {
					match br.cond {
						ast.NodeError {	// only 'else'
							stmts = gen.ast_node(br)
							out << $tmpl('c_templates/else_block.tmpl.c')#[..-1]
						}
						else {			//'else if'
							cond = gen.ast_node(br.cond).join('')
							stmts = gen.ast_node(br)
							out << $tmpl('c_templates/else_if_block.tmpl.c')#[..-1]
						}
					}
					// if br.cond.type_name().str() == 'unknown v.ast.Expr' { // only 'else'
					// 	stmts = gen.ast_node(br)
					// 	out << $tmpl('c_templates/else_block.tmpl.c')#[..-1]
					// } else {	//'else if'
					// 	cond = gen.ast_node(br.cond).join('')
					// 	stmts = gen.ast_node(br)
					// 	out << $tmpl('c_templates/else_if_block.tmpl.c')#[..-1]
					// }
				}
			}
		}
	}
	// println('>>>>>>>>>>>>>>>>>>>> ${out} <<<<<<<<<<<<<<<<<<<<')	
	return out
}

// if_expr_comptime is the code generation function for compilation time 'if' expressions.
fn (mut gen Gen) if_expr_comptime(node ast.IfExpr) []string { // basic shape of an "if" expression
	mut out := []string{}

	if node.is_expr { // in case of conditional assignment
		for br in node.branches {
			if br.stmts.len > 0 { 
				out << gen.single_assign(	gen.cur_left, 
											gen.cur_left_type, 
											gen.cur_op, 
											(br.stmts[0] as ast.ExprStmt).expr	)
			}
		}
	} else {
		// println('?????????????????????????? ${node} ???????????????????????')
		for br in node.branches {
			if br.stmts.len > 0 {
				out << gen.ast_node(br)
			}
		}
	}
	return out
}