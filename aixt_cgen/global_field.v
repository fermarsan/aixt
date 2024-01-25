// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: global_field.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation global field.
module aixt_cgen

import v.ast

fn (mut gen Gen) global_field(node ast.GlobalField) string {
	mut out := ''
	gen.idents[node.name] = struct { // add the new symbol
		kind: ast.IdentKind.global
		typ: node.typ
	}
	mut var_type := gen.table.type_kind(gen.idents[node.name].typ).str()
	// println(var_type)
	// print('===${node.expr}=== ')
	// if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
	match node.expr {
		ast.EmptyExpr {
			// print('===${node.expr}=== ')
			out += if gen.setup.value(var_type).string() == 'char []' {
				'char ${node.name.after('.')}[];\n'
			} else {
				'${gen.setup.value(var_type).string()} ${node.name.after('.')};\n'
			}
		}
		ast.CastExpr {
			out += if gen.setup.value(var_type).string() == 'char []' {
				'char ${node.name.after('.')}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
			} else {
				'${gen.setup.value(var_type).string()} ${node.name.after('.')} = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
			}								
		} 
		else {
			out += if gen.setup.value(var_type).string() == 'char []' {
				'char ${node.name.after('.')}[] = ${gen.ast_node(node.expr)};\n'
			} else {
				'${gen.setup.value(var_type).string()} ${node.name.after('.')} = ${gen.ast_node(node.expr)};\n'
			}
		}
	}	
	// println(out)
	// println(gen.symbol_table())
	return out
}
