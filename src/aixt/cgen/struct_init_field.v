// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module cgen

import v.ast

// struct_init_field is the code generation function for struct fields.
fn (mut gen Gen) struct_init_field(node ast.StructInitField) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	expr := gen.ast_node(node.expr).join('')
	out << '${expr},\t// ${node.name} = ${expr}'
	return out
}
