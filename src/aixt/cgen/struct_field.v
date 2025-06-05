// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// struct_field is the code generation function for struct fields.
fn (mut gen Gen) struct_field(node ast.StructField) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	mut ref, mut var_type := gen.get_str_c_type(node.typ, false)
	var_name := node.name//.replace('.', '__')
	expr := node.default_expr
	match expr {
		ast.EmptyExpr {
			len := ''
			if var_type == 'string' {
				out << $tmpl('c_templates/decl_string_fixed.tmpl.c')#[..-1]
			} else {
				out << $tmpl('c_templates/decl.tmpl.c')#[..-1]
			}
		}
		ast.CastExpr {
			var_value := gen.ast_node((node.default_expr as ast.CastExpr).expr).join('')
			if var_type == 'string' {
				len := ''
				out << $tmpl('c_templates/decl_assign_string.tmpl.c')#[..-1]
			} else {
				out << $tmpl('c_templates/decl_assign.tmpl.c')#[..-1]
			}								
		}
		ast.ArrayInit {
			array_init := (node.default_expr as ast.ArrayInit)
			ref, var_type = gen.get_str_c_type(array_init.elem_type, false)
			len := array_init.exprs.len
			var_value := gen.ast_node(node.default_expr).join('')
			if array_init.is_fixed {
				out << $tmpl('c_templates/decl_assign_array_fixed.tmpl.c')#[..-1]
			} else {
				out << $tmpl('c_templates/decl_assign_array.tmpl.c')#[..-1]
			}
		}
		else {
			var_value := gen.ast_node(node.default_expr).join('')
			if var_type == 'string' {
				len := ''
				out << $tmpl('c_templates/decl_assign_string.tmpl.c')#[..-1]
			} else {
				out << $tmpl('c_templates/decl_assign.tmpl.c')#[..-1]
			}
		}
	}
	return out
}
