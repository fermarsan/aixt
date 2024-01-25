// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: enum_field.v
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: code generation for enum fields.
module aixt_cgen

import v.ast

fn (mut gen Gen) enum_field(node ast.EnumField) string {
	match node.expr {
		ast.EmptyExpr {
			return '${node.name},\n'
		} 
		else {
			return '${node.name} = ${gen.ast_node(node.expr)},\n'
		}
	}
}