// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: err_war_check.v
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: check the Aixt transpiler errors and warnings (based on v.ast.file.errors)
//              this is 
module aixt_cgen

fn (mut gen Gen) err_war_check()  {
	msg_exceptions := [ // V error message exceptions in Aixt
		'is immutable, declare it with `mut`',
		'expected `#define`',
		'unknown function:',
	]

	for i in 0 .. gen.file.errors.len {	// look for each exception message by index 
		message := gen.file.errors[i].message
		for msg in msg_exceptions {
			if message.contains(msg) {
				gen.file.errors.delete(i)
				gen.err_war_check()	// recursively deleting
				break
			}
		}
	}
}