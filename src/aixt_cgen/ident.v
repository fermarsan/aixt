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
	// println('################## ${node} ##################')
	return if node.name.contains('.') {
		['${node.name.replace('.', '__')}'] if gen.code_gen else []	
	} else {
		['${node.name}'] if gen.code_gen else []	//['${node.mod}__${node.name}']
	}
	// return if node.mod == 'main' {
	// 	['${node.name}']	
	// } else {
	// 	['${node.mod}__${node.name}']
	// }
	// return ['${node.name.all_after('main.').replace('.', '__')}']
	// return ['${node.mod}__${gen.cur_fn}__${node.name}']
	// return ['${node.mod}_${node.scope.start_pos}_${node.scope.end_pos}__${node.name}']
}