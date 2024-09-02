// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// global_field is the code generation function for global fields.
fn (mut gen Gen) global_field(node ast.GlobalField) []string {
	mut out := []string{}
	mut var_kind := gen.table.type_kind(node.typ).str()
	var_name := node.name.replace('.', '__')
	expr := node.expr
	match expr {
		ast.EmptyExpr {
			len := ''
			var_c_type := gen.setup.compiler.value(var_kind).string()	
			if var_c_type == 'char []' {
				out << $tmpl('c_templates/decl_string_fixed.c')
			} else {
				out << $tmpl('c_templates/decl.c')
			}
		}
		ast.CastExpr {
			var_value := gen.ast_node((node.expr as ast.CastExpr).expr).join('')
			var_c_type := gen.setup.compiler.value(var_kind).string()
			if var_c_type == 'char []' {
				len := ''
				out << $tmpl('c_templates/decl_assign_string.c')
			} else {
				out << $tmpl('c_templates/decl_assign.c')
			}								
		}
		ast.ArrayInit {
			array_init := (node.expr as ast.ArrayInit)
			var_type:= gen.table.type_kind(array_init.elem_type).str()
			var_c_type := gen.setup.compiler.value(var_type).string()
			len := array_init.exprs.len
			var_value := gen.ast_node(node.expr).join('')
			if array_init.is_fixed {
				out << $tmpl('c_templates/decl_assign_array_fixed.c')
			} else {
				out << $tmpl('c_templates/decl_assign_array.c')
			}
		}
		else {
			var_value := gen.ast_node(node.expr).join('')
			var_c_type := gen.setup.compiler.value(var_kind).string()
			if var_c_type == 'char []' {
				len := ''
				out << $tmpl('c_templates/decl_assign_string.c')
			} else {
				out << $tmpl('c_templates/decl_assign.c')
			}
		}
	}
	return out
}