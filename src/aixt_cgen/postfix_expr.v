// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// postfix_expr is the code generation function for postfix expressions.
fn (mut gen Gen) postfix_expr(node ast.PostfixExpr) string {
	return '${gen.ast_node(node.expr)}${node.op}'
}