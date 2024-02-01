// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

// err_war_print prints Aixt transpiler warnings and errors (based on v.ast.file)
fn (mut gen Gen) err_war_print() {
	mut w_count, mut e_count := 0, 0
	for file in gen.files {
		w_count += file.warnings.len
		e_count += file.errors.len
	}
	println('\n${w_count} warning(s), ${e_count} error(s)')
	for file in gen.files {
		for w in file.warnings {
			println('warning: ${w.message}')
			// println('\t${w.details}')
		}
	}
	for file in gen.files {
		for e in file.errors {
			println('error: ${e.message}')
			// println('\t${e.details}')
		}
	}
}