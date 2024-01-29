// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: sym_table_print.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: print the table of all symbols.
module aixt_cgen

fn (mut gen Gen) sym_table_print() {
	println('\n===== Symbol table =====')
	println(' ==== global scope ==== ')
	print('${gen.symbol_table(gen.file.global_scope)}')
	println(' ======= scope ======== ')
	print('${gen.symbol_table(gen.file.scope)}')
}