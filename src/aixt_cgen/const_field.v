// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// const_field is the code generation function for constant definitions.
// This works for single definitions:
// ```v
// const max_count = 20
// ```
// and block definitions:
// ```v
// const(
// 	max = 50
// 	min = 5
// )
// ```
fn (mut gen Gen) const_field(node ast.ConstField) []string {
	mut out := []string{}
	// println('================== ${node.name} ==================')
	var_kind := gen.table.type_kind(node.typ).str()
	var_name := if node.mod.str() == 'main' {
		node.name.replace('main.', '')
	} else {
		node.name.replace('.', '__')
	}
	match var_kind {
		'array' {
			array_init := (node.expr as ast.ArrayInit)
			var_type:= gen.table.type_kind(array_init.elem_type).str()
			var_c_type := gen.setup.compiler_types[var_type]
			len := array_init.exprs.len
			var_value := gen.ast_node(node.expr).join('')
			out << 'const ' + $tmpl('c_templates/decl_assign_array_fixed.c')#[..-1]
		}				
		'string' {
			var_value := gen.ast_node(node.expr).join('')
			len := ''
			out << 'const ' + $tmpl('c_templates/decl_assign_string.c')#[..-1]
		}
		else {
			if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
				var_value := gen.ast_node((node.expr as ast.CastExpr).expr).join('')
				if gen.setup.compiler_types[var_kind] == 'char []' {
					len := ''
					out << 'const ' + $tmpl('c_templates/decl_assign_string.c')#[..-1]
				} else {
					var_c_type := gen.setup.compiler_types[var_kind]
					out << 'const ' + $tmpl('c_templates/decl_assign.c')#[..-1]
				}								
			} else {
				var_value := gen.ast_node(node.expr).join('')
				var_c_type := gen.setup.compiler_types[	match var_kind {		// var literal kind standardization
													'f64' { 'float_literal' }
													'int' { 'int_literal' }
													else { var_kind }
												}]
				out << 'const ' + $tmpl('c_templates/decl_assign.c')#[..-1]
			}
		}
	}
	return out
}