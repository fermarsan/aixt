// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// float_literal is the code generation function for floating point literals.
// ``` v
// a = 2.28718 
// ``` 
fn (mut gen Gen) float_literal(node ast.FloatLiteral) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	return [node.val]
}