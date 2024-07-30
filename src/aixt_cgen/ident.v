// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// ident is the code generation function for identifiers.
fn (mut gen Gen) ident(node ast.Ident) []string {
	// println('\n${node.mod} #### ${gen.table.cur_fn.name} #### ${node.name}\n') //  -- ${node.scope.parent}')
	// println('################## ${node.scope.parent} ##################')
	// println('################## ${node.comptime} ##################')
	match node.language {
		.c {
			return [node.name.replace('C.', '')]
		}
		else {
			return if node.mod == 'main' {
				[node.name.replace('main.', '')]
			} else {
				[node.name.replace('.', '__')]
			}
		}
	}
	// return [node.name.replace('${node.mod}.', '')]
}