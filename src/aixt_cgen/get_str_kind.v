// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// gen.get_str_kind gets the variable kind from the symbol table
fn (mut gen Gen) get_str_kind(typ ast.Type) string {
	var_type := gen.table.type_kind(typ).str()
	return if var_type == 'int' {
		'i32'
	} else {
		var_type
	}
}