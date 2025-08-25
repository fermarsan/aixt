// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// selector_expr is the code generation fucntion for selector expressions,
// such as expr.field
fn (mut gen Gen) selector_expr(node ast.SelectorExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	if node.expr.str().contains('C.') {
		return ['${node.expr.str().replace('C.', '')}.${node.field_name}']
	}
	else {
		// ref, var_type = gen.get_str_c_type(node.typ, false)
		// println('>>>>>>>>>>>>>>>>>> ${node.typ} <<<<<<<<<<<<<<<<<<')
		// return ['']
		return if node.expr_type.is_ptr() {
			['${node.expr}->${node.field_name}']
		} else {
			['${node.expr}.${node.field_name}']
		}
	}
}