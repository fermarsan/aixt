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
fn (mut gen Gen) const_field(node ast.ConstField) string {
	mut out := ''
	mut var_kind := gen.table.type_kind(node.typ).str()
	// print('\n\n(${var_kind})\n\n')
	// print('\n\n(${node.expr})\n\n')
	if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
		out += if gen.setup.value(var_kind).string() == 'char []' {
			'const char ${node.name}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		} else {
			'const ${gen.setup.value(var_kind).string()} ${node.name} = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		}								
	} else {
		var_kind = match var_kind {		// var literal kind standardization
			'f64' { 'float_literal' }
			'int' { 'int_literal' }
			else { var_kind }
		}
		out += if gen.setup.value(var_kind).string() == 'char []' {
			'const char ${node.name}[] = ${gen.ast_node(node.expr)};\n'
		} else {
			'const ${gen.setup.value(var_kind).string()} ${node.name} = ${gen.ast_node(node.expr)};\n'
		}
	}
	
	return if node.mod == 'main' {
		out.replace('main.', '')
	} else {
		out.replace('.', '__')
	}
}
