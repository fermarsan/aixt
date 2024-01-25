// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: bool_literal.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for boolean literals.
module aixt_cgen

import v.ast

fn (mut gen Gen) bool_literal(node ast.BoolLiteral) string {
	return node.val.str()
}