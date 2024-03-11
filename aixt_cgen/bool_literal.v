// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// bool_literal is the code generation function for boolean literals.
// ```v
// a := true
// ```
fn (mut gen Gen) bool_literal(node ast.BoolLiteral) string {
	return node.val.str()
}