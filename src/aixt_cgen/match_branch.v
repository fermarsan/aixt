// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// match_branch is the code generation function for 'match' branches.
fn (mut gen Gen) match_branch(node ast.MatchBranch) []string { // statements match branch expressions
	mut out := []string{}
	mut stmts := []string{}
	// println('\n\n++++ ${node} ++++\n\n')
	for st in node.stmts {
		stmts << gen.ast_node(st).join('')
	}
	if node.is_else {
		out << $tmpl('c_templates/match_else_branch.c')#[..-1]
	} else {
		if node.exprs.len == 1 {	// single expression match{
			expr := node.exprs[0].str()
			out << $tmpl('c_templates/match_branch.c')#[..-1]
		} else {
			panic('Multi-expression matches do not allowed...')	
		}
	}
	return out
}