// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// asm_stmt is the code generation function for inline asm blocks.
fn (mut gen Gen) asm_stmt(node ast.AsmStmt) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut c_line := '{'
	// println("+++++++++++++++\n${node.clobbered}\n+++++++++++++++")
	// println("+++++++++++++++\n${node.templates}\n+++++++++++++++")
	c_line += '}'
	return [c_line]
}