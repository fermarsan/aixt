// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// global_field is the code generation function for global fields.
fn (mut gen Gen) global_field(node ast.GlobalField) string {
	mut out := ''
	mut var_kind := gen.table.type_kind(node.typ).str()
	// print('\n\n##########(${var_kind})##########\n\n')
	// print('\n\n##########(${node.expr})##########\n\n')
	match node.expr {
		ast.EmptyExpr {
			out += if gen.setup.value(var_kind).string() == 'char []' {
				'char ${node.name.after('.')}[];\n'
			} else {
				'${gen.setup.value(var_kind).string()} ${node.name.after('.')};\n'
			}
		}
		ast.CastExpr {
			out += if gen.setup.value(var_kind).string() == 'char []' {
				'char ${node.name.after('.')}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
			} else {
				'${gen.setup.value(var_kind).string()} ${node.name.after('.')} = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
			}								
		} 
		ast.ArrayInit {
			// print('\n\n##########(${(node.expr as ast.ArrayInit).elem_type})##########\n\n')
			var_kind = gen.table.type_kind((node.expr as ast.ArrayInit).elem_type).str()
			out += '${gen.setup.value(var_kind).string()} ${node.name.after('.')}[] = '
			elems := node.expr.exprs.str().replace('[', '{').replace(']', '}')
			out += '${elems};\n'
		}
		else {
			out += if gen.setup.value(var_kind).string() == 'char []' {
				'char ${node.name.after('.')}[] = ${gen.ast_node(node.expr)};\n'
			} else {
				'${gen.setup.value(var_kind).string()} ${node.name.after('.')} = ${gen.ast_node(node.expr)};\n'
			}
		}
	}
	return out
}