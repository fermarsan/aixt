// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// infix_expr is the code generation function for 'infix' expressions (binary operations).
fn (mut gen Gen) infix_expr(node ast.InfixExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	mut c_line := ''
	left := gen.ast_node(node.left).join('')
	right := gen.ast_node(node.right).join('')	
	op := node.op
	// println('-------------${node.op}-------------')
	// println('-------------${node.left_type}-------------')
	// println('-------------${node.right_type}-------------')
	// println('-------------${node.promoted_type}-------------')
	if node.left_type == ast.string_type_idx || node.right_type == ast.string_type_idx {
		gen.add_include('string.h')
		match op.str() {
			'==' {
				out << '!' + $tmpl('c_templates/comp_string.tmpl.c')#[..-1]
			} 
			'!=' {
				out <<  $tmpl('c_templates/comp_string.tmpl.c')#[..-1]
			} 
			'+' {
				len := gen.setup.default_string_len
				gen.add_definition('char __temp_str[${len}];')
				out << $tmpl('c_templates/concat_string.tmpl.c')#[..-1]
			} 
			else {
				panic('\n\nTranspiler Error:\n' +
					  '"${op}" operator not supported for strings.\n')
			}
		}
	} else if op.str() == 'in' || op.str() == '!in' {
		gen.add_definition('bool __temp_bool;')				
		obj := gen.find_obj_all_scopes(right) or {
			panic('Identifier "${right}" not found.')
		}
		len := match obj {	// limit value
			ast.Var, ast.ConstField, ast.GlobalField { (obj.expr as ast.ArrayInit).exprs.len }
			else { panic('Identifier "${right}" not found..') }
		}
		c_line = $tmpl('c_templates/in_operator.tmpl.c')#[..-1]
		if op.str() == '!in' {
			c_line += '\n__temp_bool = !__temp_bool;'
		}
		gen.to_insert_lines << c_line
		c_line = '___TO_INSERT_${gen.to_insert_lines.len - 1}___'
		out << c_line + '__temp_bool'
	} else {
		out << $tmpl('c_templates/infix_expr.tmpl.c')#[..-1]
	}
	return out
}