// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// cast_expr is the code generation fucntion for casting expressions.
fn (mut gen Gen) cast_expr(node ast.CastExpr) string {
	var_type := gen.table.type_kind(node.typ).str()
	return '(${gen.setup.value(var_type).string()})(${gen.ast_node(node.expr)})'
}