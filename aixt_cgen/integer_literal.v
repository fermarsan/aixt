// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: integer_literal.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for integer literals.
module aixt_cgen

import v.ast

fn (mut gen Gen) integer_literal(node ast.IntegerLiteral) string {
	return if node.str().contains('0o') { // if it is an octal literal
		node.val.int().str() // turn it into decimal
	} else {
		node.val
	}
}