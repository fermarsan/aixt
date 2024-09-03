// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// unsafe_expr is the code generation function for unsafe blocks.
fn (mut gen Gen) unsafe_expr(node ast.UnsafeExpr) []string {
	return gen.ast_node(node.expr)
}