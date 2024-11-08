// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast
// import v.checker

// ident is the code generation function for identifiers.
fn (mut gen Gen) ident(node ast.Ident) []string {
	// println('================== ${node} ==================')
	// println('\n${node.mod} #### ${gen.table.cur_fn.name} #### ${node.name}\n') //  -- ${node.scope.parent}')
	// println('################## ${node.scope.parent} ##################')

	// mut checker_ := checker.new_checker(gen.table, gen.pref)
	// checker_.check_files(gen.files)

	// println('################## ${node.name} ##################')
	// println('################## ${node.mod} ##################')
	// println('################## ${node.kind} ##################')
	match node.language {
		.c {
			return [node.name.replace('C.', '')]
		}
		else {
			// return if node.mod == 'main' {
			// 	[node.name.replace('main.', '').replace('.', '__')]
			return if node.kind.str() == 'constant' {
				['_const_${node.name.replace('.', '__')}']
			} else {
				[node.name.replace('.', '__')]
			}
		}
	}
	// return [node.name.replace('${node.mod}.', '')]
}