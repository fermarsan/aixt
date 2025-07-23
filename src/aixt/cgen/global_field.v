// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// global_field is the code generation function for global fields.
fn (mut gen Gen) global_field(node ast.GlobalField) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	// println(node)
	mut out := []string{}
	mut ref, mut var_type := gen.get_str_c_type(node.typ, false)

	// println('>>>>>>>>>>>>>>>>>> global: ${var_type} <<<<<<<<<<<<<<<<<<')
	var_name := node.name.replace('.', '__')
	expr := node.expr
	match expr {
		ast.EmptyExpr {
			len := ''
			if var_type == 'string' {
				out << $tmpl('c_templates/decl_string_fixed.tmpl.c')
			} else {
				out << $tmpl('c_templates/decl.tmpl.c')
			}
		}
		ast.CastExpr {
			var_value := gen.ast_node((node.expr as ast.CastExpr).expr).join('')
			if var_type == 'string' {
				len := ''
				out << $tmpl('c_templates/decl_assign_string.tmpl.c')
			} else {
				out << $tmpl('c_templates/decl_assign.tmpl.c')
			}								
		}
		ast.ArrayInit {
			array_init := (node.expr as ast.ArrayInit)
			ref, var_type = gen.get_str_c_type(array_init.elem_type, false)
			len := array_init.exprs.len
			var_value := gen.ast_node(node.expr).join('')
			if array_init.is_fixed {
				out << $tmpl('c_templates/decl_assign_array_fixed.tmpl.c')
			} else {
				out << $tmpl('c_templates/decl_assign_array.tmpl.c')
			}
		}
		else {
			var_value := gen.ast_node(node.expr).join('')
			if var_type == 'string' {
				len := ''
				out << $tmpl('c_templates/decl_assign_string.tmpl.c')
			} else {
				out << $tmpl('c_templates/decl_assign.tmpl.c')
			}
		}
	}
	return out
}