// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// assign_stmt is the code generation function for assignment statements.
// This works for:
// - declaration-assignments `:=` 
// - only assignments `=` 
// and
// - cumulative-assignments `+=`, `-=` , etc. 
fn (mut gen Gen) assign_stmt(node ast.AssignStmt) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	// println('node:			${node}')	
	mut out := []string{}
	gen.cur_op = node.op
	for i in 0 .. node.right.len {
		gen.cur_left = node.left[i]
		gen.cur_left_type = node.left_types[i]
		out << match node.right[i] {
			ast.IfExpr {	// conditional assignment
				// gen.ast_node(node.left[i])
				gen.ast_node(node.right[i])
			} 
			ast.MatchExpr {	// conditional assignment by a match expression 
				// gen.ast_node(node.left[i])
				gen.ast_node(node.right[i])
			} else {			
				gen.single_assign(node.left[i], node.left_types[i], node.op, node.right[i])
			}
		}
	}
	println('${out}')
	return out
}