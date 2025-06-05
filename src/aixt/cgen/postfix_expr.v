// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// postfix_expr is the code generation function for postfix expressions.
fn (mut gen Gen) postfix_expr(node ast.PostfixExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	expr := gen.ast_node(node.expr).join('')
	op := node.op
	return ['${expr}${op}']
}