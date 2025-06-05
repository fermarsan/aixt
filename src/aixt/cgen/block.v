// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// block is the code generation function for blocks.
fn (mut gen Gen) block(node ast.Block) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	if !node.is_unsafe {
		out << '{'
	}
	for st in node.stmts {
		out << gen.ast_node(st)
	}
	if !node.is_unsafe {
		out << '}'
	}
	return out
}
