// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// return_stmt is the code generation function for return statements.
fn (mut gen Gen) return_stmt(node ast.Return) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	// Be Careful....... multiple values return
	expr := gen.ast_node(node.exprs[0]).join('')
	ref, var_type := gen.get_str_c_type(node.types[0], false)
	return ['return ((${var_type}${ref}) ${expr});']
}