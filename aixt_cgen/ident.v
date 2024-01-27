// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: ident.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for identifiers.
module aixt_cgen

import v.ast

fn (mut gen Gen) ident(node ast.Ident) string {
	// println('${node.name}-${node.scope.parent}')
	return node.name.after('.')
}