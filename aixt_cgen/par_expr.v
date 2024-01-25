// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: par_expr.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for expressions in parenthesis.
module aixt_cgen

import v.ast

fn (mut gen Gen) par_expr(node ast.ParExpr) string {
	return '(${gen.ast_node(node.expr)})'
}