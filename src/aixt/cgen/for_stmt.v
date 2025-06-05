// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// for_stmt is the code generation function for the bare 'for' statement.
fn (mut gen Gen) for_stmt(node ast.ForStmt) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	cond := if node.is_inf { 'true' }  else { gen.ast_node(node.cond).join('') }
	mut stmts := []string{}
	for st in node.stmts {
		stmts << gen.ast_node(st)
	}
	return [ $tmpl('c_templates/for.tmpl.c')#[..-1] ]
}