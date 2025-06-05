// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// par_expr is the code generation function for expressions in parenthesis.
fn (mut gen Gen) par_expr(node ast.ParExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	return ['(${gen.ast_node(node.expr).join('')})']
}