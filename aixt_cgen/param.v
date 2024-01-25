// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: param.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for parameters.
module aixt_cgen

import v.ast

fn (mut gen Gen) param(node ast.Param) string {
	var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())		
	return '${var_type.string()} ${node.name}'
}