// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// integer_literal is the code generation function for integer literals.
// ``` v
// a := 10
// ``` 
fn (mut gen Gen) integer_literal(node ast.IntegerLiteral) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	return if node.str().contains('0o') { // if it is an octal literal
		[node.val.int().str()] // turn it into decimal
	} else {
		[node.val]
	}
}