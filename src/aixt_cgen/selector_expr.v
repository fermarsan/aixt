// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// selector_expr is the code generation fucntion for selector expressions,
// such as expr.field
fn (mut gen Gen) selector_expr(node ast.SelectorExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	if node.expr.str().contains('C.') {
		return ['${node.expr.str().replace('C.', '')}.${node.field_name}']
	}
	else {
		return ['${node.expr}.${node.field_name}']
	}
}