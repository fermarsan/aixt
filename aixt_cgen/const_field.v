// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: const_field.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation constants definition.
module aixt_cgen

import v.ast

fn (mut gen Gen) const_field(node ast.ConstField) string {
	mut out := ''
	gen.idents[node.name] = struct { // add the new symbol
		kind: ast.IdentKind.constant
		typ: node.typ
	}
	mut var_type := gen.table.type_kind(gen.idents[node.name].typ).str()
	// println(var_type)
	if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
		out += if gen.setup.value(var_type).string() == 'char []' {
			'const char ${node.name.after('.')}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		} else {
			'const ${gen.setup.value(var_type).string()} ${node.name.after('.')} = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		}								
	} else {
		out += if gen.setup.value(var_type).string() == 'char []' {
			'const char ${node.name.after('.')}[] = ${gen.ast_node(node.expr)};\n'
		} else {
			'const ${gen.setup.value(var_type).string()} ${node.name.after('.')} = ${gen.ast_node(node.expr)};\n'
		}
	}
	return out
}
