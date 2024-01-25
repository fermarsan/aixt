// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: postfix_expr.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for postfix expressions.
module aixt_cgen

import v.ast

fn (mut gen Gen) postfix_expr(node ast.PostfixExpr) string {
	return '${gen.ast_node(node.expr)}${node.op}'
}