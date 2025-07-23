// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// string_literal is the code generation function for string literals.
// ``` v
// str := 'Aixt'
// ``` 
fn (mut gen Gen) string_literal(node ast.StringLiteral) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	return ['"${node.val}"']
}