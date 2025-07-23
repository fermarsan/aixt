// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// prefix_expr is the code generation function for prefix expressions.
fn (mut gen Gen) prefix_expr(node ast.PrefixExpr) []string {	
	expr := gen.ast_node(node.right).join('')
	op := node.op
	return ['${op}${expr}']
}