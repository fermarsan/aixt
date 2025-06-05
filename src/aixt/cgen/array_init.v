// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// array_init is the code generation function for arrays initialization.
fn (mut gen Gen) array_init(node ast.ArrayInit) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut c_line := ''
	if node.is_fixed {
		if node.has_val {	// [2,4,7,9]!
			c_line = gen.join_exprs(node.exprs)
		} else if node.has_init {	// [3]int{init: 0}
			c_line = gen.fill_init(node.init_expr, node.exprs[0])
		}
	} else {
		len := 	if node.has_cap { 
					node.cap_expr
					
			   	} else { 
					if node.has_len { 
						node.len_expr
					} else {
						ast.Expr(ast.IntegerLiteral{ val: node.exprs.len.str() })
					}
				}
		// println('>>>>>>>>>>>>>>>>>> len: ${len} <<<<<<<<<<<<<<<<<<')
		if node.has_init {	// []int{len: 3, init: 0} or []int{cap: 3, init: 0} or []int{len: 3, cap: 3, init: 0}
			c_line = gen.fill_init(node.init_expr, len)
		} else {
			c_line = gen.join_exprs(node.exprs)
		}
	}
	return [c_line]
}

fn (mut gen Gen) join_exprs(exprs []ast.Expr) string {
	mut c_line := '{'
	for ex in exprs {
		c_line += '${gen.ast_node(ex).join('')}, '
	}
	return c_line#[..-2] + '}'
}

fn (mut gen Gen) fill_init(expr ast.Expr, len ast.Expr) string {
	mut c_line := '{'
	for _ in 0..len.str().int() {
		c_line += '${gen.ast_node(expr).join('')}, '
	}
	return c_line#[..-2] + '}' 
}