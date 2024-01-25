// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: prefix_expr.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for prefix expressions.
module aixt_cgen

import v.ast

fn (mut gen Gen) prefix_expr(node ast.PrefixExpr) string {
	return '${node.op}${gen.ast_node(node.right)}'
}