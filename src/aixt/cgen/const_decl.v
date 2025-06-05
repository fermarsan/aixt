// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// const_decl is the code generation function for constant declarations.
fn (mut gen Gen) const_decl(node ast.ConstDecl) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	for f in node.fields {
		out << gen.ast_node(f)
	}
	return out
}