// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: enum_val.v
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: code generation for enum values.
module aixt_cgen

import v.ast

fn (mut gen Gen) enum_val(node ast.EnumVal) string {
	return '${node.val}'
}