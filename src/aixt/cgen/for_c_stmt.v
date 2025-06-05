// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// for_c_stmt is the code generation function for the c-style 'for' statements.
fn (mut gen Gen) for_c_stmt(node ast.ForCStmt) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	init := gen.ast_node(node.init).join('')#[..-1]
	cond := gen.ast_node(node.cond).join('')
	inc := gen.ast_node(node.inc).join('')#[..-1]
	mut stmts := []string{}
	for st in node.stmts {
		stmts << gen.ast_node(st)
	}
	return [ $tmpl('c_templates/for_c.tmpl.c')#[..-1] ]
}