// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// kind_and_type prints the kind and type of a identifier.
fn (mut gen Gen) kind_and_type(object ast.ScopeObject) string {
	mut msg := match object {
		ast.ConstField {
			'Constant -- ${gen.table.type_symbols[object.expr.get_pure_type()].str()}'//.after_char(`.`)}'
		}
		ast.GlobalField {
			'Global -- ${gen.table.type_symbols[object.typ].str()}'//.after_char(`.`)}'
		}
		ast.Var {
			'Variable -- ${gen.table.type_symbols[object.typ].str()}'//.after_char(`.`)}'
		}
		else {
			'Asm Reg -- ${gen.table.type_symbols[object.typ].str()}'//.after_char(`.`)}'
		}
	}
	return msg //.replace('&', '')
}