// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// bool_literal is the code generation function for boolean literals.
// ``` v
// a := true
// ``` 
fn (mut gen Gen) bool_literal(node ast.BoolLiteral) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	return [node.val.str()]
}