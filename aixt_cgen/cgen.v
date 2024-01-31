// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: cgen.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This file contains the C code generation functions of the Aixt project.

module aixt_cgen

import v.ast
// import v.token
import v.pref
import v.parser
import v.checker
import toml

// Gen is the struct that defines all the necessary data for the code generation
pub struct Gen {
mut:	
	files 		[]&ast.File = [ unsafe { nil }] 
	table 		&ast.Table = unsafe { nil }
	cur_scope	&ast.Scope = unsafe { nil }
	tr_path 	string
	src_paths	[]string
	out   		string
	incls		string
	defs		string
	cur_fn		string
	level_cont	int
pub mut:
	pref  		&pref.Preferences = unsafe { nil }
	setup 		toml.Doc
}

// gen is the main function of the code generation.
// It receives the source path (file or folder), and return a string with the generated code.
pub fn (mut gen Gen) gen(source_path string) string {
	// gen.temps_cont = 0
	gen.level_cont = 0
	gen.defs = ''
	gen.incls = ''
	// gen.pref.is_script = true

	// gen.find_sources(source_path)
	// println(src_paths)

	// gen.files = parser.parse_files(gen.src_paths, gen.table, gen.pref)

	// mut checker_ := checker.new_checker(gen.table, gen.pref)
	// for file in gen.files {
	// 	checker_.check(mut file)
	// }
	// println(gen.table.type_symbols)

	// println('\n===== Top-down node analysis =====')
	// for file in gen.files {
	// 	gen.out += gen.ast_node(gen.file) // starts from the main node (file)
	// }

	// gen.sym_table_print()

	// gen.err_war_check()
	// gen.err_war_print()
	
	gen.out_format()

	if gen.file.errors.len != 0 {	// clear out stream if any error exist
		gen.out = ''
	}
	
	return gen.out
}