// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// if_expr is the code generation function for 'if' expressions.
fn (mut gen Gen) if_expr(node ast.IfExpr) []string { // basic shape of an "if" expression
	mut out := []string{}
	cond := gen.ast_node(node.branches[0].cond).join('')
	if node.is_expr { // in case of conditional assignment
		if node.is_comptime {	
			println('${cond}')
			out << match cond {
				'on_linux' {
					'#if defined(__linux) || defined(linux)'
				}
				else {
					'#if defined(${cond})'
				}
			}
			out << if gen.cur_op.str() == ':=' { // declaration-assignment
				gen.single_decl_assign(
					gen.cur_left, 
					gen.cur_left_type, 
					(node.branches[0].stmts[0] as ast.ExprStmt).expr
				)
			} else { // for the rest of assignments
				gen.single_assign(
					gen.cur_left, 
					gen.cur_left_type, 
					gen.cur_op, 
					(node.branches[0].stmts[0] as ast.ExprStmt).expr
				)
			}
			for i, br in node.branches {
				if i >= 1 {
					if br.cond.type_name().str() == 'unknown v.ast.Expr' { // only 'else'
						out << '#else'
						out << if gen.cur_op.str() == ':=' { // declaration-assignment
							gen.single_decl_assign(
								gen.cur_left, 
								gen.cur_left_type, 
								(br.stmts[0] as ast.ExprStmt).expr
							)
						} else { // for the rest of assignments
							gen.single_assign(
								gen.cur_left, 
								gen.cur_left_type, 
								gen.cur_op, 
								(br.stmts[0] as ast.ExprStmt).expr
							)
						}
						out << '#endif'
					} else {	//'else if'
						out << '#elif ${gen.ast_node(br.cond).join('')}'
						out << if gen.cur_op.str() == ':=' { // declaration-assignment
							gen.single_decl_assign(
								gen.cur_left, 
								gen.cur_left_type, 
								(br.stmts[0] as ast.ExprStmt).expr
							)
						} else { // for the rest of assignments
							gen.single_assign(
								gen.cur_left, 
								gen.cur_left_type, 
								gen.cur_op, 
								(br.stmts[0] as ast.ExprStmt).expr
							)
						}
					}
				}
			}
		} else {
			out << 'if(${cond}) {'
			out << if gen.cur_op.str() == ':=' { // declaration-assignment
				gen.single_decl_assign(
					gen.cur_left, 
					gen.cur_left_type, 
					(node.branches[0].stmts[0] as ast.ExprStmt).expr
				)
			} else { // for the rest of assignments
				gen.single_assign(
					gen.cur_left, 
					gen.cur_left_type, 
					gen.cur_op, 
					(node.branches[0].stmts[0] as ast.ExprStmt).expr
				)
			}
			out << '}'
			for i, br in node.branches {
				if i >= 1 {
					out << 'else '
					if br.cond.type_name().str() == 'unknown v.ast.Expr' { // only 'else'
						out << '{'
						out << if gen.cur_op.str() == ':=' { // declaration-assignment
							gen.single_decl_assign(
								gen.cur_left, 
								gen.cur_left_type, 
								(br.stmts[0] as ast.ExprStmt).expr
							)
						} else { // for the rest of assignments
							gen.single_assign(
								gen.cur_left, 
								gen.cur_left_type, 
								gen.cur_op, 
								(br.stmts[0] as ast.ExprStmt).expr
							)
						}
						out << '}'
					} else {	//'else if'
						out << 'if(${gen.ast_node(br.cond).join('')}) {'
						out << if gen.cur_op.str() == ':=' { // declaration-assignment
							gen.single_decl_assign(
								gen.cur_left, 
								gen.cur_left_type, 
								(br.stmts[0] as ast.ExprStmt).expr
							)
						} else { // for the rest of assignments
							gen.single_assign(
								gen.cur_left, 
								gen.cur_left_type, 
								gen.cur_op, 
								(br.stmts[0] as ast.ExprStmt).expr
							)
						}
						out << '}' 
					}
				}
			}
			// mut c_line := '(${gen.ast_node(node.branches[0].cond).join('')}) ? '
			// c_line += gen.ast_node(node.branches[0]).join('')#[..-1] + ' : '
			// out << c_line + gen.ast_node(node.branches[1]).join('')
		}
	} else {
		if node.is_comptime {
			// println('?????????????????????????? ${node} ???????????????????????')
				
			println('${cond}')
			out << match cond {
				'on_linux' {
					'#if defined(__linux) || defined(linux)'
				}
				else {
					'#if defined(${cond})'
				}
			}
			out << gen.ast_node(node.branches[0])
			for i, br in node.branches {
				if i >= 1 {
					if br.cond.type_name().str() == 'unknown v.ast.Expr' { // only 'else'
						out << '#else'
						out << gen.ast_node(br)
						out << '#endif'
					} else {	//'else if'
						out << '#elif ${gen.ast_node(br.cond).join('')}'
						out << gen.ast_node(br)
					}
				}
			}
		} else {
			out << 'if(${cond}) {'
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
	}
	return out
}