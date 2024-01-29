// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: err_war_print.v
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: print Aixt transpiler warnings and errors (based on v.ast.file)
module aixt_cgen

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