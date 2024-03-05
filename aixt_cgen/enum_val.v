// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// enum_val is the code generation function for enum values.
fn (mut gen Gen) enum_val(node ast.EnumVal) string {
	// println('\n${node.enum_name}\n')
	return '${node.enum_name.after('.')}.${node.val}'
}