// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast
// import v.checker

// ident is the code generation function for identifiers.
fn (mut gen Gen) ident(node ast.Ident) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node.name} <<<<<<<<<<<<<<<<<<')
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