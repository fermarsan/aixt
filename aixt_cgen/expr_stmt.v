// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: expr_stmt.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for a expression statements.
module aixt_cgen

import v.ast

fn (mut gen Gen) expr_stmt(node ast.ExprStmt) string {
	return '${gen.ast_node(node.expr)};\n'
}