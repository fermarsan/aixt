// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// if_expr is the code generation function for 'if' expressions.
fn (mut gen Gen) if_expr(node ast.IfExpr) []string { // basic shape of an "if" expression
	mut out := []string{}
	println('????????????????????????? ${node.left} ???????????????????????????')
	if node.is_expr { // in case of conditional assignment
		// if node.is_comptime {
		// 	if gen.ast_node(node.branches[0].cond).join('') == 'linux' {
		// 		out << '#if defined(__linux) || defined(linux)'
		// 	}
		// }



		// if gen.ast_node(node.branches[0].cond).join('') == ':=' { // declaration-assignment
		// 	gen.single_decl_assign(node.left[i], node.left_type[i], node.right[i])
		// } else { // for the rest of assignments
		// 	gen.single_assign(node.left[i], node.left_type[i], node.op, node.right[i])
		// }
		mut c_line := '(${gen.ast_node(node.branches[0].cond).join('')}) ? '
		c_line += gen.ast_node(node.branches[0]).join('')#[..-1] + ' : '
		out << c_line + gen.ast_node(node.branches[1]).join('')
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