// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// single_decl_assign is the code generation function for single declaration-assignment statements.
// This works for:
// - declaration-assignments `:=`
fn (mut gen Gen) single_decl_assign(left ast.Expr, left_type ast.Type, right ast.Expr) []string {
	mut out := []string{}
	var_kind := gen.table.type_kind(left_type).str()
	var_name := gen.ast_node(left).join('')
	match var_kind {		
		'array', 'array_fixed' {
			array_init := (right as ast.ArrayInit)
			var_type := gen.table.type_kind(array_init.elem_type).str()
			var_c_type := gen.setup.value(var_type).string()
			len := array_init.exprs.len
			var_value := gen.ast_node(right).join('')
			if array_init.is_fixed {
				out << $tmpl('c_templates/decl_assign_array_fixed.c.tmpl')
			} else {
				out << $tmpl('c_templates/decl_assign_array.c.tmpl')
			}

		}
		'string' {
			gen.add_include('string.h')
			len := gen.setup.value('string_default_len').int()
			var_value := gen.ast_node(right).join('')
			out << $tmpl('c_templates/decl_assign_string.c.tmpl')
		}
		'enum' {
			var_c_type := 'enum ${(right as ast.EnumVal).enum_name.replace('.', '__')} '
			var_value := gen.ast_node(right).join('')
			out << $tmpl('c_templates/decl_assign.c.tmpl')
		}
		else {
			var_c_type := gen.setup.value(var_kind).string()
			var_value := if right.type_name() == 'v.ast.CastExpr' {
				gen.ast_node((right as ast.CastExpr).expr).join('')
			} else {
				gen.ast_node(right).join('')
			}
			out << $tmpl('c_templates/decl_assign.c.tmpl')	// call the template
		}
	}
	return out
}