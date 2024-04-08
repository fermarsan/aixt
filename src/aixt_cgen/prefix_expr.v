// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// prefix_expr is the code generation function for prefix expressions.
fn (mut gen Gen) prefix_expr(node ast.PrefixExpr) string {
	return '${node.op}${gen.ast_node(node.right)}'
}