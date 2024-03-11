// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// enum_decl is code generation function for enum declarations.
fn (mut gen Gen) enum_decl(node ast.EnumDecl) string {
	mut out := 'enum ${node.name.replace('.', '__')} {\n'
	for f in node.fields {
		out += '${gen.ast_node(f)}'
	}
	out += '};\n'
	println('')
	return out
}