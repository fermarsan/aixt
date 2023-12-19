// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: str.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for strings operations.
module aixt_cgen

import v.ast

fn (mut gen Gen) gen_string_eq(str1 string, str2 string) string {
	return match gen.setup.value('backend').string() {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		'c'			{ '!strcmp(${str1}, ${str2})' }
		else 		{ '.c' }
	}
}