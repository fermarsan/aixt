// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: utils.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation utils.
module aixt_cgen

import v.ast

fn (mut gen Gen) add_include(name_ext string) {
	if !gen.includes.contains(name_ext) {
		gen.includes += '#include <${name_ext}>\n'
	}
}

fn (mut gen Gen) add_custom_include(path_ext string) {
	if !gen.includes.contains(path_ext) {
		gen.includes += '#include "${path_ext}"\n'
	}
}

fn (mut gen Gen) add_definition(def string) {
	if !gen.definitions.contains(def) {
		gen.definitions += '${def}\n'
	}
}

fn (mut gen Gen) kind_and_type(object ast.ScopeObject) string {
	mut msg := match object {
		ast.ConstField {
			'Constant -- ${gen.table.type_symbols[object.expr.get_pure_type()].str().after_char(`.`)}'
		}
		ast.GlobalField {
			'Global -- ${gen.table.type_symbols[object.typ].str().after_char(`.`)}'
		}
		ast.Var {
			'Variable -- ${gen.table.type_symbols[object.typ].str().after_char(`.`)}'
		}
		else {
			'Asm Reg  -- ${gen.table.type_symbols[object.typ].str().after_char(`.`)}'
		}
	}
	return msg.replace('&', '')
}

fn (mut gen Gen) symbol_table(scope ast.Scope) string {
	mut msg := ''
	for _, val in scope.objects {
		msg += '${val.name.after_char(`.`)} -- ${gen.kind_and_type(val)}\n'
	}
	for child in scope.children {
		msg += gen.symbol_table(child) 
	}
	return msg
}

fn (mut gen Gen) out_format() {
	gen.out = gen.out.replace('___includes_block___', gen.includes)
	gen.out = gen.out.replace('___definitions_block___', gen.definitions)
	gen.out = gen.out.replace('\n\n\n;', '\n')
	gen.out = gen.out.replace('\n\n;', '\n---')
	gen.out = gen.out.replace('}\n;', '}')
	mut temp := ''
	mut ind_count := 0
	for c in gen.out {
		match rune(c) {
			`\n` {
				temp += '\n' + '\t'.repeat(ind_count)
			}
			`{` {
				ind_count++
				temp += rune(c).str()
			}
			`}` {
				ind_count--
				temp += rune(c).str()
			}
			else {
				temp += rune(c).str()
			}
		}
	}
	temp = temp.replace('\t}', '}')
	gen.out = temp + '\n'
}