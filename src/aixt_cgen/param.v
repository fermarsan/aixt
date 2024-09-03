// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// param is the code generation function for parameters.
fn (mut gen Gen) param(node ast.Param) []string {
	var_type := gen.setup.compiler.value(ast.new_table().type_symbols[node.typ].str())		
	return if var_type.string() == 'char []' {
		['char ${node.name}[]']		// for strings
	} else {
		['${var_type.string()} ${node.name}']
	}
}