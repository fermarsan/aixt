// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module builder

// err_war_check checks the Aixt transpiler errors and warnings (based on v.ast.file.errors).
// This defines a list of error exceptions (allowed in Aixt but not in V)
pub fn (mut b Builder) err_war_check() {
	msg_exceptions := match b.setup.backend {	// V error message exceptions in Aixt 
		'nxc' {
			[ 	
				'mutex',
			]
		}
		'arduino' {
			[ 	
				'mutex',
			]
		}
		else {
			[ 	
				'no exceptions',
			]
		}
	}
			// 'is immutable, declare it with `mut` ',
			// 'expected `#define` ',
			// 'unknown function:',
			// 'undefined ident:',
			// 'has no constant or function',
			// 'cannot call a function that does not have a body',
			// 'used as value in argument',
			// '` used as value',
			// 'returns 0 value',
			// 'non-bool',
			// 'mismatched types `void`  and',
			// 'on type `void` ',
			// 'unknown method or field',
			// 'expression does not return a value',
			// 'expected `void`',
			// '`int` has no property `',
			// 'unexpected symbol `int`',
	for j, mut file in b.parsed_files {
		for i in 0 .. file.errors.len {	// look for each exception message by index
			if j == 0 {	// discard all the error messages for builtin.c.v
				file.errors.delete(i)
				b.err_war_check()	// recursively deleting
				break
			} else {
				message := file.errors[i].message
				for msg in msg_exceptions {
					if message.contains(msg) {
						file.errors.delete(i)
						b.err_war_check()	// recursively deleting
						break
					}
				}
			}
		}
	}
}


// err_war_print prints Aixt transpiler warnings and errors (based on v.ast.file)
pub fn (mut b Builder) err_war_print() {
	mut w_count, mut e_count := 0, 0
	for file in b.parsed_files {
		w_count += file.warnings.len
		e_count += file.errors.len
	}
	println('\n${w_count} warning(s), ${e_count} error(s)')
	for file in b.parsed_files {
		for w in file.warnings {
			println('warning: ${w.message}\t(${file.path_base})')
			// println('\t${w.details}')
		}
	}
	for file in b.parsed_files {
		for e in file.errors {
			println('error: ${e.message}\t(${file.path_base})')
			// println('\t${e.details}')
		}
	}
}

// err_war_clear clears Aixt transpiler warnings and errors (based on v.ast.file)
pub fn (mut b Builder) err_war_clear() {
	for mut file in b.parsed_files {
		file.errors.clear()
		file.warnings.clear()
	}
}