// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: err_war_check.v
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: check the Aixt transpiler errors and warnings (based on v.ast.file.errors)
module aixt_cgen

fn (mut gen Gen) err_war_check()  {	
	mut indexes := []int{}
	msg_exceptions := [ // V error message exceptions in Aixt
		'is immutable, declare it with `mut` to make it mutable',
	]

	for i in 0..gen.file.errors.len {	// look for each exception message by index 
		message := gen.file.errors[i].message
		for msg in msg_exceptions {
			if message.contains(msg) {
				indexes << i
			}
		}
	}

	for i in indexes {	// delete exceptions by index
		gen.file.errors.delete(i)
	}
}