// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// cast_expr is the code generation fucntion for casting expressions.
fn (mut gen Gen) cast_expr(node ast.CastExpr) []string {
	var_type := gen.table.type_kind(node.typ).str()
	var_c_type := if !var_type.contains('.') {
		gen.setup.compiler_types[var_type]
	} else {
		var_type
	}
	expr := gen.ast_node(node.expr).join('')
	return ['(${var_c_type})(${expr})']
}