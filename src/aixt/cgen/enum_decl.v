// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// enum_decl is code generation function for enum declarations.
fn (mut gen Gen) enum_decl(node ast.EnumDecl) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	// println('--------------- enum decl ------------------')
	mut out := ['enum ${node.name.replace('.', '__')} {']
	for f in node.fields {
		out << gen.ast_node(f)
	}
	out << '};'
	return out
}