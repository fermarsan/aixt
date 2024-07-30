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
	mut c_line := ''
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
				c_line = $tmpl('c_templates/decl_assign_array_fixed.c')#[..-1]
			} else {
				c_line = $tmpl('c_templates/decl_assign_array.c')#[..-1]
			}
		}
		'string' {
			gen.add_include('string.h')
			len := gen.setup.value('string_default_len').int()
			var_value := gen.ast_node(right).join('')
			c_line = $tmpl('c_templates/decl_string_fixed.c')#[..-1]
			c_line = $tmpl('c_templates/assign_string.c')#[..-1]
		}
		'enum' {
			var_c_type := 'enum ${(right as ast.EnumVal).enum_name.replace('.', '__')} '
			var_value := gen.ast_node(right).join('')
			c_line = $tmpl('c_templates/decl_assign.c')#[..-1]
		}
		else {
			var_c_type := gen.setup.value(var_kind).string()
			var_value := if right.type_name() == 'v.ast.CastExpr' {
				gen.ast_node((right as ast.CastExpr).expr).join('')
			} else {
				gen.ast_node(right).join('')
			}
			c_line = $tmpl('c_templates/decl_assign.c')#[..-1]
		}
	}
	// if gen.setup.value('backend').string() == 'arduino' {
	// 	gen.definitions << c_line
	// } else {
		out << c_line
	// }
	return out
}
