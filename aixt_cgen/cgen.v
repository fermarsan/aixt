// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT

// Description: This file contains the C code generation functions of the Aixt.
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
	files 		[]&ast.File
	table 		&ast.Table = unsafe { nil }
	cur_scope	&ast.Scope = unsafe { nil }
	tr_path 	string
	src_paths	[]string
	out   		string
	headers		string
	macros		string
	defs		string
	cur_fn		string
	file_count	int
	level_cont	int
pub mut:
	pref  		&pref.Preferences = unsafe { nil }
	setup 		toml.Doc
}

// gen is the main function of the code generation.
// It receives the source path (file or folder), and return a string with the generated code.
pub fn (mut gen Gen) gen(source_path string) string {
	gen.init_output_file()

	gen.find_sources('${gen.tr_path}/ports/${gen.setup.value('path').string()}/api')
	gen.find_sources(source_path)

	gen.files = parser.parse_files(gen.src_paths, gen.table, gen.pref)
	mut checker_ := checker.new_checker(gen.table, gen.pref)
	checker_.check_files(gen.files)

	println('\n===== Top-down node analysis =====')
	for i, file in gen.files {	// source folder
		gen.file_count = i
		gen.out += gen.ast_node(file) // starts from the main node (file)
	}
	
	gen.sym_table_print()
	gen.err_war_check()
	gen.err_war_print()

	mut e_count := 0
	for file in gen.files {
		e_count += file.errors.len
	}
	if e_count != 0 {	// clear out stream if any error exist
		gen.out = ''
	}
	
	gen.out_format()
	return gen.out
}