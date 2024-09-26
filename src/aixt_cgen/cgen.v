// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT

// Description: This file contains the C code generation functions of the Aixt.
module aixt_cgen

import v.ast
import v.token
import v.pref
import v.parser
import v.checker
import aixt_setup	

// Gen is the struct that defines all the necessary data for the code generation
pub struct Gen {
pub mut:
// mut:	
	files 			[]&ast.File
	table 			&ast.Table = unsafe { nil }
	cur_scope		&ast.Scope = unsafe { nil }
	cur_left		ast.Expr
	cur_left_type	ast.Type
	cur_op			token.Kind
	cur_cond		ast.Expr
	transpiler_path	string
	// imports			[]string
	source_paths	[]string
	out   			[]string
	c_preproc_cmds	[]string
	api_mod_paths	map[string]string
	// includes		[]string
	// macros		[]string
	definitions		[]string
	init_cmds		[]string
	to_insert_lines	[]string
	cur_fn			string
	file_count		int
	level_count		int
// pub mut:
	pref  			&pref.Preferences = unsafe { nil }
	setup			aixt_setup.Setup
}

// gen is the main function of the code generation.
// It receives the source path (file or folder), and return a string with the generated code.
pub fn (mut gen Gen) gen(source_path string) string {

	gen.load_mod_paths()

	mut checker_ := checker.new_checker(gen.table, gen.pref)

	api_paths := gen.setup.api_paths

	// adds the builtin file first
	gen.source_paths << '${gen.transpiler_path}/ports/${api_paths[0]}/api/builtin.c.v'

	gen.add_sources(source_path)

	// for path in api_paths {
	// 	gen.add_sources('${gen.transpiler_path}/ports/${path}/api')	// main source folder
	// }
	// for path in gen.source_paths {
	// 	println('--- ${path} ---')
	// }
	// $if windows {
	//	file = parser.parse_file(source_path, mut gen.table, .skip_comments, gen.pref)
	// } $else {
	// 	file = parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
	// }
	gen.files = parser.parse_files(gen.source_paths, mut gen.table, gen.pref)
	checker_.check_files(gen.files)

	gen.init_output_file()

	// solve issue in Windows
	// if gen.files.len > gen.source_paths.len {
	// 	gen.files.pop()
	// }

	println('\n===== Top-down node analysis (Code generation) =====')
	temp_files := gen.files
	for i, file in temp_files {	// source folder
		gen.file_count = i
		gen.out << gen.ast_node(file) // starts from the main node (file)
	}
	
	gen.sym_table_print()
	gen.err_war_check()
	gen.err_war_print()

	mut e_count := 0
	for i, file in gen.files {
		// println('-----file: ${file.path}\t${file.mod}')
		e_count += if i != 0 { file.errors.len } else { 0 }
	}
	if e_count != 0 {	// clear out stream if any error exist
		gen.out = []
	}
	
	return gen.out_format()
}