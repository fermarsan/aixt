// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2014
// License: MIT
module aixt_cgen

import v.ast

// ast_file is the function for ast.File code generation.
fn (mut gen Gen) ast_file(node ast.File) string {
	println(node.path)
	mut out := ''
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	return out
}