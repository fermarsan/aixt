// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// expr_stmt is the code generation function for expression statements.
fn (mut gen Gen) expr_stmt(node ast.ExprStmt) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	return ['${gen.ast_node(node.expr).join('\n')};']
}