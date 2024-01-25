// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: const_decl.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for constant declarations.
module aixt_cgen

import v.ast

fn (mut gen Gen) const_decl(node ast.ConstDecl) string {
	mut out := ''
	for f in node.fields {
		out += '${gen.ast_node(f)}'
	}
	return out
}