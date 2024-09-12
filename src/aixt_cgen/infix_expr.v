// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// infix_expr is the code generation function for 'infix' expressions (binary operations).
fn (mut gen Gen) infix_expr(node ast.InfixExpr) []string {
	mut out := []string{}
	left := gen.ast_node(node.left).join('')
	right := gen.ast_node(node.right).join('')	
	op := node.op
	// println('-------------${node.left_type}-------------')
	// println('-------------${node.right_type}-------------')
	// println('-------------${node.promoted_type}-------------')
	if node.left_type == ast.string_type_idx || node.right_type == ast.string_type_idx {
		gen.add_include('string.h')
		match op.str() {
			'==' {
				out << '!' + $tmpl('c_templates/comp_string.c')#[..-1]
			} 
			'!=' {
				out <<  $tmpl('c_templates/comp_string.c')#[..-1]
			} 
			'+' {
				len := gen.setup.string_default_len
				gen.add_definition('char __temp_str[${len}];')
				out << $tmpl('c_templates/concat_string.c')#[..-1]
			} 
			else {
				panic('\n\nTranspiler Error:\n' +
					  '"${op}" operator not supported for strings.\n')
			}
		}
	} else {
		out << $tmpl('c_templates/infix_expr.c')#[..-1]
	}
	return out
}