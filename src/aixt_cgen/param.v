// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// param is the code generation function for parameters.
fn (mut gen Gen) param(node ast.Param) []string {
	// var_type := gen.get_str_kind(ast.new_table().type_symbols[node.typ])	
	var_type := gen.get_str_kind(node.typ)		
	return if var_type == 'string' {
		['char ${node.name}[]']		// for strings
	} else {
		['${var_type} ${node.name}']
	}
}