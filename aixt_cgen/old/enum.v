// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: enum.v
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: code generation for enum definitions.
module aixt_cgen

import v.ast

fn (mut gen Gen) enum_decl(node ast.EnumDecl) string {
	gen.type_names << 'enum ${node.name.after_char(`.`)}'
	mut out := 'enum ${node.name.after_char(`.`)} {\n'
	for f in node.fields {
		out += '${gen.ast_node(f)}'
	}
	out += '};'
	println('\n\n${gen.type_names}\n\n')
	return out
}

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

fn (mut gen Gen) enum_val(node ast.EnumVal) string {
	return '${node.val}'
}