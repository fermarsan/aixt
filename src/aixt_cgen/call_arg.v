// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// call_arg is the code generation function for call arguments.
fn (mut gen Gen) call_arg(node ast.CallArg) string {	
	return '${gen.ast_node(node.expr)}'
}