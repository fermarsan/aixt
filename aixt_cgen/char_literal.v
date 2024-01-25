// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: char_literal.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for character literals.
module aixt_cgen

import v.ast

fn (mut gen Gen) char_literal(node ast.CharLiteral) string {
	return "'${node.val}'"
}