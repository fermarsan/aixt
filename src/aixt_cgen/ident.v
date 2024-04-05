// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// ident is the code generation function for identifiers.
fn (mut gen Gen) ident(node ast.Ident) string {
	// println('\n${node.mod} -- ${node.name}') //  -- ${node.scope.parent}')
	// return node.name.replace('.', '__')
	// return if node.mod == 'main' {
	// 	'${node.name}'	
	// } else {
	// 	'${node.mod}__${node.name}'
	// }
	return '${node.name.all_after('main.').replace('.', '__')}'
}