// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
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
// - cumulative-assignments `+=`, `-=`, etc. 
fn (mut gen Gen) single_assign(left ast.Expr, left_type ast.Type, op token.Kind, right ast.Expr) []string {
	mut out := []string{}
	var_kind := gen.table.type_kind(left_type).str()
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
						if gen.setup.value('fixed_size_arrays').bool() {
							panic('\n\nTranspiler Error:\n' +
								  'For now dynamic-size arrays are not allowed.\n')
						}
					}
					'string' {
						gen.add_include('string.h')
						match op.str() {
							'=' {
								out << $tmpl('c_templates/assign_string.c')#[..-1]
							} 
							'+=' {
								out << $tmpl('c_templates/accumulate_string.c')#[..-1]
							}	
							else {
								panic('\n\nTranspiler Error:\n' +
									  '"${op}" operator not supported for strings.\n')
							}
						}
					}
					else {
						out << $tmpl('c_templates/assign.c')#[..-1]
					}
				} 
			} 
			else {
				out << $tmpl('c_templates/assign.c')#[..-1]
			}
		}
	}
	return out
}