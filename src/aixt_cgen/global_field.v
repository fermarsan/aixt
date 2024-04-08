// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// global_field is the code generation function for global fields.
fn (mut gen Gen) global_field(node ast.GlobalField) string {
	// print('\n\n##########(${node})##########\n\n')
	mut out := ''
	mut var_kind := gen.table.type_kind(node.typ).str()
	// print('\n\n##########(${var_kind})##########\n\n')
	// print('\n\n##########(${node.expr})##########\n\n')
	match node.expr {
		ast.EmptyExpr {
			out += if gen.setup.value(var_kind).string() == 'char []' {
				'char ${node.name.replace('.', '__')}[];\n'
			} else {
				'${gen.setup.value(var_kind).string()} ${node.name.replace('.', '__')};\n'
			}
		}
		ast.CastExpr {
			out += if gen.setup.value(var_kind).string() == 'char []' {
				'char ${node.name.replace('.', '__')}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
			} else {
				'${gen.setup.value(var_kind).string()} ${node.name.replace('.', '__')} = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
			}								
		} 
		ast.ArrayInit {
			var_kind = gen.table.type_kind((node.expr as ast.ArrayInit).elem_type).str()
			out += '${gen.setup.value(var_kind).string()} ${node.name.replace('.', '__')}[] = '
			elems := node.expr.exprs.str().replace('[', '{').replace(']', '}')
			out += '${elems};\n'
		}
		else {
			out += if gen.setup.value(var_kind).string() == 'char []' {
				'char ${node.name.replace('.', '__')}[] = ${gen.ast_node(node.expr)};\n'
			} else {
				'${gen.setup.value(var_kind).string()} ${node.name.replace('.', '__')} = ${gen.ast_node(node.expr)};\n'
			}
		}
	}
	return out
}