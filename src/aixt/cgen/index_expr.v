// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// index_expr is the code generation function for 'index' expressions (array indexation).
fn (mut gen Gen) index_expr(node ast.IndexExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	// Be careful, multiple indexing missing
	array_name := gen.ast_node(node.left).join('')
	index := gen.ast_node(node.index).join('')
	return ['${array_name}[${index}]']
}