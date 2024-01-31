// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

// err_war_print prints Aixt transpiler warnings and errors (based on v.ast.file)
fn (mut gen Gen) err_war_print() {
	println('\n${gen.file.warnings.len} warning(s), ${gen.file.errors.len} error(s)')
	for w in gen.file.warnings {
		println('warning: ${w.message}')
		// println('\t${w.details}')
	}
	for e in gen.file.errors {
		println('error: ${e.message}')
		// println('\t${e.details}')
	}
}