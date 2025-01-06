// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// sym_table_print prints the table of all symbols.
fn (mut gen Gen) sym_table_print() {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')

	println(' ==== global scope ==== ')
	// println(gen.table.type_symbols)
	// println(gen.table.type_idxs)		
	print(gen.symbol_table(gen.table.global_scope))
	println(' ======= scope ======== ')
	for file in gen.files {
		println('${file.mod.name}:\t${file.path_base}')
		print(gen.symbol_table(file.scope))
	}
	println('\n')
	// println('SYMBOL TABLE:\n${gen.table.type_symbols} len: ${gen.table.type_symbols.len}')
}

// symbol_table prints recursively the symbol table os a specific scope
fn (mut gen Gen) symbol_table(scope ast.Scope) string {
	mut msg := ''
	// println('#######\n ${scope.objects} \n#######')
	for key, val in scope.objects {
		// msg += '${val.name.after_char(`.` )} -- ${gen.kind_and_type(val)}\n'
		if val.name != 'input' {	// ignore 'input' var of enum declaration
			msg += '\t${key} -- ${gen.kind_and_type(val)}\n'
		}
	}
	for child in scope.children {
		msg += gen.symbol_table(child) 
	}
	return msg
}


// kind_and_type prints the kind and type of a identifier.
fn (mut gen Gen) kind_and_type(object ast.ScopeObject) string {
	mut msg := match object {
		ast.ConstField {
			'Constant -- ${gen.table.type_symbols[object.expr.get_pure_type()].str()}'//.after_char(`.` )}'
		}
		ast.GlobalField {
			// 'Global -- ${gen.table.type_symbols[object.typ].str()}'//.after_char(`.` )}'
			if object.typ >= 0x10000 {	// if var is mutable
				'Global (ref) -- ${gen.table.type_symbols[object.typ ^ 0x10000].str()}'//.after_char(`.` )}'
			} else {
				'Global -- ${gen.table.type_symbols[object.typ].str()}'//.after_char(`.` )}'
			}
		}
		ast.Var {
			if object.typ >= 0x10000 {	// if var is mutable
				'Variable (mut) -- ${gen.table.type_symbols[object.typ ^ 0x10000].str()}'//.after_char(`.` )}'
			} else {
				'Variable -- ${gen.table.type_symbols[object.typ].str()}'//.after_char(`.` )}'
			}
		}
		else {
			'Asm Reg -- ${gen.table.type_symbols[object.typ].str()}'//.after_char(`.` )}'
		}
	}
	return msg	//.replace('&', '')
}