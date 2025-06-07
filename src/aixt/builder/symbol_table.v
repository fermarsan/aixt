// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module builder

import v.ast

// sym_table_print prints the table of all symbols.
pub fn (mut b Builder) sym_table_print() {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')

	println('\n ==== global scope ==== ')
	// println(b.table.type_symbols)
	// println(b.table.type_idxs)		
	print(b.symbol_table(b.table.global_scope))
	println('\n ======= scope ======== ')
	for file in b.parsed_files {
		println('${file.mod.name}:\t${file.path_base}')
		print(b.symbol_table(file.scope))
	}
	println('\n')
	// println('SYMBOL TABLE:\n${b.table.type_symbols} len: ${b.table.type_symbols.len}')
}

// symbol_table prints recursively the symbol table os a specific scope
pub fn (mut b Builder) symbol_table(scope ast.Scope) string {
	mut msg := ''
	// println('#######\n ${scope.objects} \n#######')
	for key, val in scope.objects {
		// msg += '${val.name.after_char(`.` )} -- ${gen.kind_and_type(val)}\n'
		if val.name != 'input' {	// ignore 'input' var of enum declaration
			msg += '\t${key} -- ${b.kind_and_type(val)}\n'
		}
	}
	for child in scope.children {
		msg += b.symbol_table(child) 
	}
	return msg
}


// kind_and_type prints the kind and type of a identifier.
pub fn (mut b Builder) kind_and_type(object ast.ScopeObject) string {
	mut msg := ''
	match object {
		ast.ConstField {
			typ := ast.idx_to_type(object.expr.get_pure_type().idx())
			msg = 'Constant -- ${b.table.type_symbols[typ].str()}'//.after_char(`.` )}'
		}
		ast.GlobalField {
			typ := ast.idx_to_type(object.typ.idx()) 
			msg = if object.typ.nr_muls() != 0 {	// if var is a reference
				'Global (ref) -- ${b.table.type_symbols[typ].str()}'//.after_char(`.` )}'
			} else {
				'Global -- ${b.table.type_symbols[typ].str()}'//.after_char(`.` )}'
			}
		}
		ast.Var {
			typ := ast.idx_to_type(object.typ.idx()) 
			msg = if object.is_mut {	// if var is mutable
				'Variable (mut) -- ${b.table.type_symbols[typ].str()}'//.after_char(`.` )}'
			} else {
				'Variable -- ${b.table.type_symbols[typ].str()}'//.after_char(`.` )}'
			}
		}
		else {
			typ := ast.idx_to_type(object.typ.idx())
			msg = 'Asm Reg -- ${b.table.type_symbols[typ].str()}'//.after_char(`.` )}'
		}
	}
	return msg	//.replace('&', '')
}