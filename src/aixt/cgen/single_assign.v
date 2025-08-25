// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast
import v.token

// single_assign is the code generation function for single assignment and declaration-assignment statements.
// This works for:
// - declaration-assignments `:=
// - only assignments `=` 
// and
// - cumulative-assignments `+=`, `-=` , etc. 
fn (mut gen Gen) single_assign(left ast.Expr, left_type ast.Type, op token.Kind, right ast.Expr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${left_type.str()} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	ref, mut var_type := gen.get_str_c_type(left_type, false)
	// println('>>>>>>>>>>>>>>>>>> ${var_type} <<<<<<<<<<<<<<<<<<')
	var_name := gen.ast_node(left).join('')
	var_value := gen.ast_node(right).join('')
	left_expr := left
	if op.str() == ':=' { // declaration-assignment
		out = gen.single_decl_assign(left, left_type, right)
	} else if left.str().contains('C.') {	// C variable assignment
		out << $tmpl('c_templates/c_assign.tmpl.c')#[..-1]
	} else {
		match left_expr {
			ast.Ident {	// if it is a simple variable
				match var_type {
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
					'struct' {
						var_type = var_type.replace('.', '__')
						out << $tmpl('c_templates/assign_struct.tmpl.c')#[..-1]
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
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	mut c_line := ''
	mut ref, mut var_type := gen.get_str_c_type(left_type, false)
	var_name := gen.ast_node(left).join('')
	var_kind := gen.table.type_kind(left_type).str() 
	match var_kind {		
		'array', 'array_fixed' {
			array_init := (right as ast.ArrayInit)
			// println('>>>>>>>>>>>>>>>>>> ${array_init} <<<<<<<<<<<<<<<<<<')
			ref, var_type = gen.get_str_c_type(array_init.elem_type, false)
			len := 	if array_init.has_cap { 
						array_init.cap_expr
					} else { 
						if array_init.has_len { 
							array_init.len_expr
						} else {
							ast.Expr(ast.IntegerLiteral{ 
										val: array_init.exprs.len.str() 
									})
						}
					}
			if right.str() == 'ast.EmptyExpr' {	// declaration only
				c_line = $tmpl('c_templates/decl_assign_array_empty.tmpl.c')#[..-1]
			} else {
				var_value := gen.ast_node(right).join('')
				if var_value == '' {
					c_line = $tmpl('c_templates/decl_assign_array_empty.tmpl.c')#[..-1]
				} else if array_init.is_fixed {
					c_line = $tmpl('c_templates/decl_assign_array_fixed.tmpl.c')#[..-1]
				} else {
					c_line = $tmpl('c_templates/decl_assign_array.tmpl.c')#[..-1]
				}
			}
		}
		'string' {
			gen.add_include('string.h')
			len := gen.setup.default_string_len
			c_line = $tmpl('c_templates/decl_string_fixed.tmpl.c')#[..-1]	// first, the declaration
			if right.str() != 'ast.EmptyExpr' {
				var_value := gen.ast_node(right).join('')
				c_line += '\n' + $tmpl('c_templates/assign_string.tmpl.c')#[..-1]
			}
			println('${c_line}')
		}
		'enum' {
			ref = ''
			if right.str() == 'ast.EmptyExpr' {	// declaration only
				c_line = $tmpl('c_templates/decl.tmpl.c')#[..-1]
			} else {
				var_type = 'enum ${(right as ast.EnumVal).enum_name.replace('.', '__')} '
				var_value := gen.ast_node(right).join('')
				c_line = $tmpl('c_templates/decl_assign.tmpl.c')#[..-1]
			}
		}
		'struct' {
			var_type = var_type.replace('.', '__')
			if right.str() == 'ast.EmptyExpr' {	// declaration only
				// println('>>>>>>>>>>>>>>>>>> ${right.str()} <<<<<<<<<<<<<<<<<<')
				// c_line = $tmpl('c_templates/decl.tmpl.c')#[..-1]
				panic('"struct" definition can not be empty')
			} else {
				var_value := if right.type_name() == 'v.ast.CastExpr' {
					gen.ast_node((right as ast.CastExpr).expr).join('')
				} else {
					gen.ast_node(right).join('')
				}
				c_line = $tmpl('c_templates/decl_assign_struct.tmpl.c')#[..-1]
			}

		}
		else {
			if right.str() == 'ast.EmptyExpr' {	// declaration only
				// println('>>>>>>>>>>>>>>>>>> ${right.str()} <<<<<<<<<<<<<<<<<<')
				c_line = $tmpl('c_templates/decl.tmpl.c')#[..-1]
			} else {
				var_value := if right.type_name() == 'v.ast.CastExpr' {
					gen.ast_node((right as ast.CastExpr).expr).join('')
				} else {
					gen.ast_node(right).join('')
				}
				c_line = $tmpl('c_templates/decl_assign.tmpl.c')#[..-1]
			}
		}
	}
	// if gen.setup.value('backend').string() == 'arduino' {
	// 	gen.definitions << c_line
	// } else {
		out << c_line
	// }
	return out
}