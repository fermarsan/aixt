// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module cgen

import v.ast

// array_decompose is the code generation function for arrays decompose.
fn (mut gen Gen) array_decompose(node ast.ArrayDecompose) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut c_line := ''
	c_line = node.expr.str()
	// if node.exprs.len != 0 {
	// 	for ex in node.exprs {
	// 		c_line += '${gen.ast_node(ex).join('')}, '
	// 	}
	// 	c_line = c_line#[..-2] + '}'
	// }
	// // println("+++++++++++++++\n${c_line}\n+++++++++++++++")
	return [c_line]
}