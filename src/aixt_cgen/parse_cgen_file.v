// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT

// Description: This file contains the C code generation functions of the Aixt.
module aixt_cgen

import v.ast
import v.parser
import v.checker
// import v.pref

// parse_cgen_file, parces and generates code from a new source file
// this is used mainly for modules
pub fn (mut gen Gen) parse_cgen_file(source_path string) string {
	mut file := &ast.File(unsafe { nil })	// parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
	
	$if windows {
		file = parser.parse_file(source_path, mut gen.table, .skip_comments, gen.pref)
	} $else {
		file = parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
	}

	mut checker_ := checker.new_checker(gen.table, gen.pref)
	checker_.check(mut file)

	println('\n===== Top-down node analysis =====')
	gen.out += gen.ast_node(file) // starts from the main node (file)


	// mut e_count := 0
	// for file in gen.files {
	// 	e_count += file.errors.len
	// }
	// if e_count != 0 {	// clear out stream if any error exist
	// 	gen.out = ''
	// }
	
	// gen.out_format()
	return gen.out
}