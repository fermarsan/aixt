// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// param is the code generation function for parameters.
fn (mut gen Gen) param(node ast.Param) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	// println('>>>>>>>>>>>>>>>>>> ${node.typ} <<<<<<<<<<<<<<<<<<')
	ref, mut var_type := gen.get_str_c_type(node.typ, false)	
	var_type = var_type.replace('.', '__')
	// println('>>>>>>>>>>>>>>>>>> ${ref}, ${var_type} <<<<<<<<<<<<<<<<<<')	
	return match var_type {
		'string' {
			['char ${node.name}[]']		// for strings
		}
		else {
			['${var_type} ${ref}${node.name}']
		}
	}
}