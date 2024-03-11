// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// sym_table_print prints the table of all symbols.
fn (mut gen Gen) sym_table_print() {
	println('\n===== Symbol table =====')
	println(' ==== global scope ==== ')
	print('${gen.symbol_table(gen.table.global_scope)}')
	println(' ======= scope ======== ')
	for file in gen.files {
		print('${gen.symbol_table(file.scope)}')
	}
}