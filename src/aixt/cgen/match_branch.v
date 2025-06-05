// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

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
		if gen.match_as_nested_if {
			out << $tmpl('c_templates/else_block.tmpl.c')#[..-1]
		} else {
			out << $tmpl('c_templates/match_else_branch.tmpl.c')#[..-1]
		}
	} else {
		mut cond := ''
		match node.exprs[0] {
			ast.InfixExpr {	// comparisons: a < 5
				for ex in node.exprs {
					exp := gen.ast_node(ex).join('')
					cond += '(${exp}) == ${gen.cur_cond} || '
				} 
				cond = cond#[..-4]	// remove the last ' ||
				out << $tmpl('c_templates/if_block.tmpl.c')#[..-1]
			}
			ast.RangeExpr {	// ranges: 0 ... 9				
				for ex in node.exprs {
					exp := (ex as ast.RangeExpr)
					cond += '(${gen.cur_cond} >= ${gen.ast_node(exp.low).join('')} && ' +
							'${gen.cur_cond} <= ${gen.ast_node(exp.high).join('')}) || '
				} 
				cond = cond#[..-4]	// remove the last '
				out << $tmpl('c_templates/if_block.tmpl.c')#[..-1]
			}
			else {	// literals or identifiers: 7
				exprs := node.exprs.map(gen.ast_node(it).join(''))	
				out << $tmpl('c_templates/match_branch.tmpl.c')#[..-1]
			}
		}

	// if gen.match_as_nested_if {
	// 	if node.is_else {
	// 	out << $tmpl('c_templates/else_block.tmpl.c')#[..-1]
	// 	} else {
	// 		mut cond := ''
	// 		for ex in node.exprs {
	// 			cond += '(${ex.str()}) == ${gen.cur_cond} || '
	// 		}
	// 		cond = cond#[..-4]
	// 		out << $tmpl('c_templates/if_block.tmpl.c')#[..-1]
	// 	}
	// } else { // regular match expressions
	// 	if node.is_else {
	// 	out << $tmpl('c_templates/match_else_branch.tmpl.c')#[..-1]
	// 	} else {
	// 		exprs := node.exprs.map(it.str())
	// 		out << $tmpl('c_templates/match_branch.tmpl.c')#[..-1]
	// 	}
	// }
	}
	return out
}
