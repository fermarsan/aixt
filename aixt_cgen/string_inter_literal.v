// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// string_inter_literal is the code generation function for string literals with interpolation.
// ```v
// str := 'Hello ${var_name}...'
// ```
fn (mut gen Gen) string_inter_literal(node ast.StringInterLiteral) string {
	println(node.vals)
	println(node.exprs)
	println(node.expr_types)
	// gen.add_include('stdio.h')
	// for ex in node.exprs {
	// 	println(ex.get_pure_type())//gen.ast_node(ex)
	// }

	println(node.expr_types)
	
	return '' //sprintf(${gen.ast_node(node.left[i])}, ${gen.ast_node(node.right[i])});\n'
}