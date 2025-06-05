// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// match_expr is the code generation function for 'match' expressions.
fn (mut gen Gen) match_expr(node ast.MatchExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	// println('????????????????????\n${node}\n????????????????????')
	mut out := []string{}
	mut stmts := []string{}
	if node.is_expr { // if it is a match-assignment
		out = gen.match_assign(node)
	} else { // the rest of match expressions
		gen.cur_cond = node.cond
		match node.branches[0].exprs[0] {
			ast.InfixExpr, ast.RangeExpr {
				mut temp := gen.match_as_nested_if	// save the current state
				gen.match_as_nested_if = true
				for br in node.branches {
					stmts << gen.ast_node(br).join('')
				}
				out << stmts // match as nested if
				gen.match_as_nested_if = temp
			}
			else {
				cond := node.cond
				for br in node.branches {
					stmts << gen.ast_node(br).join('')
				}
				out << $tmpl('c_templates/match.tmpl.c')#[..-1]
			}
		}
	}
	return out
}

// match_assign is the code generation function for 'match' assignment expressions.
fn (mut gen Gen) match_assign(node ast.MatchExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut total := ''
	node_cond := gen.ast_node(node.cond).join('')
	for br in node.branches.reverse() {
		if br.is_else {
			total += '(${gen.ast_node(br.stmts[0]).join('')#[..-1]})'
		} else {
			mut cond := ''
			for ex in br.exprs {
				exp := gen.ast_node(ex).join('')
				match ex {
					ast.InfixExpr {	// comparisons: a < 5
						cond += '(${exp}) == ${node_cond} || '
					}
					ast.RangeExpr {	// ranges: 0 ... 9
						cond += '(${node_cond} >= ${gen.ast_node(ex.low).join('')} && ' +
								'${node_cond} <= ${gen.ast_node(ex.high).join('')}) || '
					}
					else {	// literals or identifiers: 7
						cond += '${node_cond} == ${exp} || '
					}
				}
			}
			cond = cond#[..-4]	// remove the last ' || '
			if_true := gen.ast_node(br.stmts[0]).join('')#[..-1]
			if_false := total
			total = $tmpl('c_templates/ternary_op.tmpl.c')#[..-1]
		}
	}
	mut assign := gen.single_assign(gen.cur_left, gen.cur_left_type, gen.cur_op, ast.empty_expr).join('')
	// println('${assign}')
	assign = '${assign#[..-3]}( ${total} );'
	return [assign]
}
