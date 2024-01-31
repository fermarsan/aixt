// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// ident is the code generation function for identifiers.
fn (mut gen Gen) ident(node ast.Ident) string {
	// println('${node.name}-${node.scope.parent}')
	return node.name.after('.')
}