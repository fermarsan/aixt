// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: float_literal.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for floating point literals.
module aixt_cgen

import v.ast

fn (mut gen Gen) float_literal(node ast.FloatLiteral) string {
	return node.val
}