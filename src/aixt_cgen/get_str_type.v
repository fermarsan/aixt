// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// get_str_type gets the variable type name from the symbol table
fn (mut gen Gen) get_str_type(typ ast.Type) string {
	println('\n\tKind:\t${gen.table.type_kind(typ).str()}\tType:\t${gen.table.type_to_str(typ)}')
	unalias_typ := if gen.table.type_kind(typ).str() == 'alias' {	// if it is defined with "type"
		gen.table.unaliased_type(typ)
	} else {	
		typ
	}
	println('\n\tUnalias type:\t${gen.table.type_to_str(unalias_typ)}')
	var_type := gen.table.type_to_str(unalias_typ)
	return if var_type == 'int' {
		'i32'
	} else {
		var_type.replace('C.', '')
	}
}
