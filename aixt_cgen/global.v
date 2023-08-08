// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: global.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation global variables definition.
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
	if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
		out += if gen.setup.value(var_type).string() == 'char []' {
			'char ${node.name.after('.')}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		} else {
			'${gen.setup.value(var_type).string()} ${node.name.after('.')} = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		}								
	} else {
		out += if gen.setup.value(var_type).string() == 'char []' {
			'char ${node.name.after('.')}[] = ${gen.ast_node(node.expr)};\n'
		} else {
			'${gen.setup.value(var_type).string()} ${node.name.after('.')} = ${gen.ast_node(node.expr)};\n'
		}
	}
	return out
}
