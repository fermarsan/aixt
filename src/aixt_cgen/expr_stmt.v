// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// expr_stmt is the code generation function for expression statements.
fn (mut gen Gen) expr_stmt(node ast.ExprStmt) string {
	return '${gen.ast_node(node.expr)};\n'
}