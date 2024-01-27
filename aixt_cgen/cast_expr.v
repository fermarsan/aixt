// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: cast_expr.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for casting expressions.
module aixt_cgen

import v.ast

fn (mut gen Gen) cast_expr(node ast.CastExpr) string {
	var_type := gen.table.type_kind(node.typ).str()
	return '(${gen.setup.value(var_type).string()})(${gen.ast_node(node.expr)})'
}