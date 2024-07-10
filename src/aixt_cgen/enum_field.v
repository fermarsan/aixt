// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// enum_field is code generation function for enum fields.
fn (mut gen Gen) enum_field(node ast.EnumField) []string {
	match node.expr {
		ast.EmptyExpr {
			return ['${node.name},'] if gen.code_gen else []
		} 
		else {
			return ['${node.name} = ${gen.ast_node(node.expr).join('')},']  if gen.code_gen else [] // '${node.name} = ${node.expr},\n'
		}
	}
}