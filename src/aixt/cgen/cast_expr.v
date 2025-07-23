// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// cast_expr is the code generation fucntion for casting expressions.
fn (mut gen Gen) cast_expr(node ast.CastExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	ref, var_type := gen.get_str_c_type(node.typ, false)
	expr := gen.ast_node(node.expr).join('')
	return ['(${var_type}${ref})(${expr})']
}