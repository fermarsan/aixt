// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// enum_decl is code generation function for enum declarations.
fn (mut gen Gen) enum_decl(node ast.EnumDecl) []string {
	// println('--------------- enum decl ------------------')
	if gen.code_gen {
		mut out := ['enum ${node.name.replace('.', '__')} {']
		for f in node.fields {
			out << gen.ast_node(f)
		}
		out << '};'
		return out
	} else {
		return ['']
	}
}