// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// range_expr is the code generation function for range expressions
fn (mut gen Gen) range_expr(node ast.RangeExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	return ['${gen.ast_node(node.low).join('')} ... ${gen.ast_node(node.high).join('')}']
}