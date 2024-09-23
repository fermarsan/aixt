// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// match_expr is the code generation function for 'match' expressions.
fn (mut gen Gen) match_expr(node ast.MatchExpr) []string {
	// mut out := []string{}
	cond := node.cond
	mut stmts := []string{}
	if node.is_expr {
		println('match assignment...')
	} else {
		for br in node.branches {
			stmts << gen.ast_node(br).join('')
		}
	}
	return [ $tmpl('c_templates/match.c')#[..-1] ]
} 