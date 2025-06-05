// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// const_field is the code generation function for constant definitions.
// This works for single definitions:
// ``` v
// const max_count = 20
// ``` 
// and block definitions:
// ``` v
// const(
// 	max = 50
// 	min = 5
// )
// ``` 
fn (mut gen Gen) const_field(node ast.ConstField) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	mut ref, mut var_type := gen.get_str_c_type(node.typ, true)
	// println('>>>>>>>>>>>>>>>>>> ${ref} , ${var_type} <<<<<<<<<<<<<<<<<<')

	if node.name.contains('cpu_freq') {
		gen.cpu_freq_defined = true
	}

	var_name := '_const_${node.name.replace('.', '__')}'
	
	if node.attrs.contains('as_macro') {
		var_value := gen.ast_node(node.expr).join('')
		out << $tmpl('c_templates/constant_as_macro.tmpl.c')#[..-1]
	} else {
		match var_type {
			'array' {
				array_init := (node.expr as ast.ArrayInit)
				ref, var_type = gen.get_str_c_type(array_init.elem_type, true)
				len := array_init.exprs.len
				var_value := gen.ast_node(node.expr).join('')
				out << 'const ' + $tmpl('c_templates/decl_assign_array_fixed.tmpl.c')#[..-1]
			}				
			'string' {
				var_value := gen.ast_node(node.expr).join('')
				len := ''
				out << 'const ' + $tmpl('c_templates/decl_assign_string.tmpl.c')#[..-1]
			}
			else {
				if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
					var_value := gen.ast_node((node.expr as ast.CastExpr).expr).join('')
					if var_type == 'string' {
						len := ''
						out << 'const ' + $tmpl('c_templates/decl_assign_string.tmpl.c')#[..-1]
					} else {
						out << 'const ' + $tmpl('c_templates/decl_assign.tmpl.c')#[..-1]
					}								
				} else {
					var_value := gen.ast_node(node.expr).join('')
					out << 'const ' + $tmpl('c_templates/decl_assign.tmpl.c')#[..-1]
				}
			}
		}
	}
	return out
}