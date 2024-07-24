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
	mut c_line := ''
	// println('================== ${node.name} ==================')
	var_kind := gen.table.type_kind(node.typ).str()
	var_name := node.name
	match var_kind {
		'array' {
			array_init := (node.expr as ast.ArrayInit)
			var_type:= gen.table.type_kind(array_init.elem_type).str()
			var_c_type := gen.setup.value(var_type).string()
			len := array_init.exprs.len
			var_value := gen.ast_node(node.expr).join('')
			c_line = 'const ' + $tmpl('c_templates/decl_assign_array_fixed.c.tmpl')#[..-1]
		}				
		'string' {
			var_value := gen.ast_node(node.expr).join('')
			c_line = $tmpl('c_templates/decl_const_string.c.tmpl')#[..-1]
		}
		else {
			if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
				var_value := gen.ast_node((node.expr as ast.CastExpr).expr).join('')
				if gen.setup.value(var_kind).string() == 'char []' {
					c_line = $tmpl('c_templates/decl_const_string.c.tmpl')#[..-1]
				} else {
					var_c_type := gen.setup.value(var_kind).string()
					c_line = 'const ' + $tmpl('c_templates/decl_assign.c.tmpl')#[..-1]
				}								
			} else {
				var_value := gen.ast_node(node.expr).join('')
				var_c_type := gen.setup.value(	match var_kind {		// var literal kind standardization
													'f64' { 'float_literal' }
													'int' { 'int_literal' }
													else { var_kind }
												} ).string()
				c_line = 'const ' + $tmpl('c_templates/decl_assign.c.tmpl')#[..-1]
			}
		}
	}
	return if c_line.contains('main.') {
		[c_line.replace('main.', '')]
	} else {
		[c_line.replace('.', '__')]
	}
}
