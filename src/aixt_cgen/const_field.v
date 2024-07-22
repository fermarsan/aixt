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
	mut var_kind := gen.table.type_kind(node.typ).str()
	// println('================== ${node.name} ==================')
	match var_kind {
		'array' {
			var_kind = gen.table.type_kind((node.expr as ast.ArrayInit).elem_type).str()
			c_line += 'const ${gen.setup.value(var_kind).string()} ' // array's element type
			c_line += '${node.name}['
			array_len := (node.expr as ast.ArrayInit).exprs.len
			if  array_len != 0 {
				c_line += '${array_len}] = ${gen.ast_node(node.expr).join('')};'
			} else {
				c_line += '];'
			}
		}				
		'string' {
			c_line += 'const char ${node.name}[] = ${gen.ast_node(node.expr).join('')};'
		}
		else {
			if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
				c_line += if gen.setup.value(var_kind).string() == 'char []' {
					'const char ${node.name}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr).join('')};'
				} else {
					'const ${gen.setup.value(var_kind).string()} ${node.name} = ${gen.ast_node((node.expr as ast.CastExpr).expr).join('')};'
				}								
			} else {
				// println('???????????????????????????????????????????? ${var_kind}')
				var_kind = match var_kind {		// var literal kind standardization
					'f64' { 'float_literal' }
					'int' { 'int_literal' }
					else { var_kind }
				}
				c_line += 'const ${gen.setup.value(var_kind).string()} ${node.name} = ${gen.ast_node(node.expr).join('')};'
			}
		}
	}
	return if c_line.contains('main.') {
		[c_line.replace('main.', '')]
	} else {
		[c_line.replace('.', '__')]
	}
}
