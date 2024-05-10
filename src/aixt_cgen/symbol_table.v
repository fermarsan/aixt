// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// symbol_table prints the symbol table os a specific scope
fn (mut gen Gen) symbol_table(scope ast.Scope) string {
	mut msg := ''
	// println('+'.repeat(25))
	for key, val in scope.objects {
		// msg += '${val.name.after_char(`.`)} -- ${gen.kind_and_type(val)}\n'
		msg += '${key} -- ${gen.kind_and_type(val)}\n'
		// println(val)
	}
	// println('-'.repeat(25))
	for child in scope.children {
		msg += gen.symbol_table(child) 
	}
	return msg
}