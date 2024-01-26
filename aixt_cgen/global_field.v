// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: global_field.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation global field.
module aixt_cgen

import v.ast

fn (mut gen Gen) global_field(node ast.GlobalField) string {
	mut out := ''
	var_kind := (*gen.table.type_symbols[node.typ]).kind.str()
	// print('\n\n(${var_kind})\n\n')
	// print('\n\n(${node.expr})\n\n')
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