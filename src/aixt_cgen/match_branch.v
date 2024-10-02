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
	if gen.match_as_nested_if {
		if node.is_else {
		out << $tmpl('c_templates/else_block.tmpl.c')#[..-1]
		} else {
			mut cond := ''
			for ex in node.exprs {
				cond += '(${ex.str()}) == ${gen.cur_cond} || '
			}
			cond = cond#[..-4]
			out << $tmpl('c_templates/if_block.tmpl.c')#[..-1]
		}
	} else { // regular match expressions
		if node.is_else {
		out << $tmpl('c_templates/match_else_branch.tmpl.c')#[..-1]
		} else {
			exprs := node.exprs.map(it.str())
			out << $tmpl('c_templates/match_branch.tmpl.c')#[..-1]
		}
	}
	return out
}
