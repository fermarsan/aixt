// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT

// Description: This file contains the C code generation functions of the Aixt.
module cgen2

import aixt.setup as aixt_setup
import v.ast
import v.token
// import v.pref
import v.parser
import v.checker
import v.builder as v_builder
import os

// Gen is the struct that defines all the necessary data for the code generation
pub struct Gen {	
	v_builder.Builder
pub mut:
	setup				aixt_setup.Setup
	aixt_path			string
	cur_scope      		&ast.Scope = unsafe { nil }
	cur_left			ast.Expr
	cur_left_type  		ast.Type
	cur_op		   		token.Kind
	cur_cond       		ast.Expr
	// imports				[]string
	source_paths		[]string
	out           		[]string
	c_preproc_cmds		[]string
	api_mod_paths  		map[string][]string
	lib_mod_paths		map[string][]string
	include_paths		[]string
	// macros			  []string
	definitions    		[]string
	init_cmds	   		[]string
	to_insert_lines		[]string
	cur_fn         		string
	file_count			int
	level_count    		int
	match_as_nested_if 	bool
	cpu_freq_defined   	bool
}

// gen is the main function of the code generation.
// It receives the source path (file or folder), and return a string with the generated code.
pub fn (mut gen Gen) gen(source_path string) string {

	gen.load_api_mod_paths()
	gen.load_lib_mod_paths()

	mut checker_ := checker.new_checker(gen.table, gen.pref)
	api_paths := gen.setup.api_paths

	// add the builtin file first
	if os.exists('${gen.aixt_path}/ports/${api_paths[0]}/api/builtin.c.v') {
		gen.source_paths << '${gen.aixt_path}/ports/${api_paths[0]}/api/builtin.c.v'
	} else {
		panic('"builtin.c.v" in have to exist in "${gen.aixt_path}/ports/${api_paths[0]}/api/"')
	}
	// add the source files in the project's main folder
	gen.add_local_sources(source_path)

	gen.find_all_sources(gen.source_paths.len)
	println('Source files:\n\t${gen.source_paths.join('\n\t')}')

	// second parse round including imports
	gen.parsed_files = parser.parse_files(gen.source_paths, mut gen.table, gen.pref)
	checker_.check_files(gen.parsed_files)
	// gen.err_war_print()

	gen.init_output_file()

	// solve issue in Windows
	// if gen.parsed_files.len > gen.source_paths.len {
	// 	gen.parsed_files.pop()
	// }

	println('\n===== Top-down node analysis (Code generation) =====')
	temp_2_files := gen.parsed_files.clone()
	for i, file in temp_2_files {	// source folder
		// println('>>>>>>>>>>>>>>>>>> ${file.imports} <<<<<<<<<<<<<<<<<<')
		gen.file_count = i
		gen.out << gen.ast_node(file) // starts from the main node (file)
	}

	// b.sym_table_print()
	// b.err_war_check()
	// b.err_war_print()

	mut e_count := 0
	for i, file in gen.parsed_files {
		// println('-----file: ${file.path}\t${file.mod}')
		e_count += if i != 0 { file.errors.len } else { 0 }
	}
	if e_count != 0 {	// clear out stream if any error exist
		gen.out = []
	}

	// copy the include files to the output folder
	for path in gen.include_paths {
		if !os.exists('${os.dir(source_path)}/${os.file_name(path)}') {
			os.cp_all(path, os.dir(source_path), false) or { panic(err) }
			println("${path}\ncopied to project's folder")
		}
	}

	return gen.out_format()
}