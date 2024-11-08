// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// get_str_c_type gets the variable type name from the symbol table
fn (mut gen Gen) get_str_c_type(typ ast.Type) (string, string) {
	ref, mut typ2 := if typ >= 0x10000 {	// reference variable
		'*', typ - 0x10000		
	} else {	// regular variable
		'',  typ
	}
	println('\n\tKind:\t${gen.table.type_kind(typ2).str()}\tType:\t${gen.table.type_to_str(typ2)} ${ref}')
	unalias_typ := match gen.table.type_kind(typ2).str() {
		'alias' {	// if it is defined with "type"
			gen.table.unaliased_type(typ2)
		} 
		'array' {
			gen.table.type_idxs['array']
		}
		else {	
			typ2
		}
	}
	println('\n\tUnalias type:\t${gen.table.type_to_str(unalias_typ)}')
	// var_type := gen.table.type_to_str( 
	// 	if unalias_typ >= 0x10000 {	// reference variable
	// 		unalias_typ - 0x10000
	// 	} else {	// regular variable
	// 		unalias_typ
	// 	})
	// ref := if unalias_typ >= 0x10000 {	// reference variable
	// 		'*'		
	// 	} else {	// regular variable
	// 		''	
	// 	}
	var_type := gen.table.type_to_str(unalias_typ)
	return if var_type == 'int' {	// replace 'int' by 'i32' to avoid compiler ambiguity
		ref, 'i32'
	} else {
		ref, var_type.replace('C.', '').replace(' ', '_')
	}
}
