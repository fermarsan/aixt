// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// char_literal is the code generation function for character literals.
// ```v
// ch := `v`
// ```
fn (mut gen Gen) char_literal(node ast.CharLiteral) string {
	return "'${node.val}'"
}