// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: string_literal.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for string literals.
module aixt_cgen

import v.ast

fn (mut gen Gen) string_literal(node ast.StringLiteral) string {
	return '"${node.val}"'
}