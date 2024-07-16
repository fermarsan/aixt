// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// symbol_table prints recursively the symbol table os a specific scope
fn (mut gen Gen) symbol_table(scope ast.Scope) string {
	mut msg := ''
	for key, val in scope.objects {
		// msg += '${val.name.after_char(`.`)} -- ${gen.kind_and_type(val)}\n'
		if val.name != 'input' {	// ignore 'input' var of enum declaration
			msg += '\t${key} -- ${gen.kind_and_type(val)}\n'
		}
	}
	for child in scope.children {
		msg += gen.symbol_table(child) 
	}
	return msg
}