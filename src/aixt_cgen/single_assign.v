// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast
import v.token

// single_assign is the code generation function for single assignment and declaration-assignment statements.
// This works for:
// - declaration-assignments `:=
// - only assignments `=` 
// and
// - cumulative-assignments `+=`, `-=` , etc. 
fn (mut gen Gen) single_assign(left ast.Expr, left_type ast.Type, op token.Kind, right ast.Expr) []string {
	mut out := []string{}
	var_kind := gen.table.type_kind(left_type).str()
	var_c_type := gen.setup.compiler_types[var_kind]
	var_name := gen.ast_node(left).join('')
	var_value := gen.ast_node(right).join('')
	left_expr := left
	if op.str() == ':=' { // declaration-assignment
		out = gen.single_decl_assign(left, left_type, right)
	} else {
		match left_expr {
			ast.Ident {	// if it is a simple variable
				match var_kind {
					'array' {
						// if gen.setup.platform.value('fixed_size_arrays').bool() {
							panic('\n\nTranspiler Error:\n' +
								  'For now dynamic-size arrays are not allowed.\n')
						// }
					}
					'string' {
						gen.add_include('string.h')
						match op.str() {
							'=' {
								out << $tmpl('c_templates/assign_string.tmpl.c')#[..-1]
							} 
							'+=' {
								out << $tmpl('c_templates/accumulate_string.tmpl.c')#[..-1]
							}	
							else {
								panic('\n\nTranspiler Error:\n' +
									  '"${op}" operator not supported for strings.\n')
							}
						}
					}
					else {
						out << $tmpl('c_templates/assign.tmpl.c')#[..-1]
					}
				} 
			} 
			else {
				out << $tmpl('c_templates/assign.tmpl.c')#[..-1]
			}
		}
	}
	return out
}


// single_decl_assign is the code generation function for single declaration-assignment statements.
// This works for:
// - declaration-assignments `:=` 
fn (mut gen Gen) single_decl_assign(left ast.Expr, left_type ast.Type, right ast.Expr) []string {
	mut out := []string{}
	mut c_line := ''
	var_kind := gen.table.type_kind(left_type).str()
	ref := ''
	var_name := gen.ast_node(left).join('')
	match var_kind {		
		'array', 'array_fixed' {
			array_init := (right as ast.ArrayInit)
			var_type := gen.table.type_kind(array_init.elem_type).str()
			var_c_type := gen.setup.compiler_types[var_type]
			len := array_init.exprs.len
			var_value := gen.ast_node(right).join('')
			if array_init.is_fixed {
				c_line = $tmpl('c_templates/decl_assign_array_fixed.tmpl.c')#[..-1]
			} else {
				c_line = $tmpl('c_templates/decl_assign_array.tmpl.c')#[..-1]
			}
		}
		'string' {
			gen.add_include('string.h')
			len := gen.setup.string_default_len
			var_value := gen.ast_node(right).join('')
			c_line = $tmpl('c_templates/decl_string_fixed.tmpl.c')#[..-1]
			c_line += '\n' + $tmpl('c_templates/assign_string.tmpl.c')#[..-1]
			println('${c_line}')
		}
		'enum' {
			var_c_type := 'enum ${(right as ast.EnumVal).enum_name.replace('.', '__')} '
			var_value := gen.ast_node(right).join('')
			c_line = $tmpl('c_templates/decl_assign.tmpl.c')#[..-1]
		}
		else {
			var_c_type := gen.setup.compiler_types[var_kind]
			var_value := if right.type_name() == 'v.ast.CastExpr' {
				gen.ast_node((right as ast.CastExpr).expr).join('')
			} else {
				gen.ast_node(right).join('')
			}
			c_line = $tmpl('c_templates/decl_assign.tmpl.c')#[..-1]
		}
	}
	// if gen.setup.value('backend').string() == 'arduino' {
	// 	gen.definitions << c_line
	// } else {
		out << c_line
	// }
	return out
}