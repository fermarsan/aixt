// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: call_arg.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for call arguments.
module aixt_cgen

import v.ast

fn (mut gen Gen) call_arg(node ast.CallArg) string {	
	return '${gen.ast_node(node.expr)}'
}