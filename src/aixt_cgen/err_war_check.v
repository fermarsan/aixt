// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

// err_war_check checks the Aixt transpiler errors and warnings (based on v.ast.file.errors).
// This defines a list of error exceptions (allowed in Aixt but not in V)
fn (mut gen Gen) err_war_check() {
	msg_exceptions := [ // V error message exceptions in Aixt
		// 'is immutable, declare it with `mut`',
		// 'expected `#define`',
		'unknown function:',
		'undefined ident:',
		'has no constant or function',
		'cannot call a function that does not have a body',
		'used as value in argument',
		'` used as value',
		'returns 0 value',
		'non-bool',
		'mutex',
		'mismatched types `void` and',
		'on type `void`',
		'unknown method or field',
		'expression does not return a value',
	]

	for j, mut file in gen.files {
		for i in 0 .. file.errors.len {	// look for each exception message by index
			if j == 0 {	// discart all the error messages for builtin.c.v
				file.errors.delete(i)
						gen.err_war_check()	// recursively deleting
						break
			} else {
				message := file.errors[i].message
				for msg in msg_exceptions {
					if message.contains(msg) {
						file.errors.delete(i)
						gen.err_war_check()	// recursively deleting
						break
					}
				}
			}
		}
	}
}