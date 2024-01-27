// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: index_expr.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for 'index' expressions (array indexation).
module aixt_cgen

import v.ast

fn (mut gen Gen) index_expr(node ast.IndexExpr) string {
	// Be careful, multiple indexing missing
	return '${gen.ast_node(node.left)}[${gen.ast_node(node.index)}]'
}