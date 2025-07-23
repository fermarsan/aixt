// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2014
// License: MIT
module cgen

import v.ast

// ast_file is the function for ast.File code generation.
fn (mut gen Gen) ast_file(node ast.File) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	println(node.path) 
	mut out := []string{}
	for st in node.stmts {
		out << gen.ast_node(st)
	}
	println('(end) File -> ${node.path}\n')
	// println('ERRORS:\t${node.errors}')
	return out
}