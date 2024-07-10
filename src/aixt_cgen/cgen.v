// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT

// Description: This file contains the C code generation functions of the Aixt.
module aixt_cgen

import v.ast
import v.pref
import toml

// Gen is the struct that defines all the necessary data for the code generation
pub struct Gen {
pub mut:
// mut:	
	files 			[]&ast.File
	table 			&ast.Table = unsafe { nil }
	cur_scope		&ast.Scope = unsafe { nil }
	transpiler_path	string
	imports			[]string
	source_paths	[]string
	out   			[]string
	c_preproc_cmds	[]string	
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
	setup 			toml.Doc
}

// gen is the main function of the code generation.
// It receives the source path (file or folder), and return a string with the generated code.
pub fn (mut gen Gen) gen(source_path string) string {
	gen.init_output_file()

	// println('++++++++++++++++\npath: ${gen.setup.value('path').string()}\n++++++++++++++++')
	gen.source_paths << '${gen.transpiler_path}/ports/${gen.setup.value('path').string()}/api/builtin.c.v'
	gen.add_sources(source_path)

	println('main source files:')	//  print source files
	for source in gen.source_paths {
		println('\t${source}')
	}

	gen.parse_check_files()		// parse and check all the source files

	// solve issue in Windows
	if gen.files.len > gen.source_paths.len {
		gen.files.pop()
	}

	println('\n===== Top-down node analysis =====')
	temp_files := gen.files
	for i, file in temp_files {	// source folder
		gen.file_count = i
		gen.out << gen.ast_node(file) // starts from the main node (file)
	}
	
	gen.sym_table_print()
	gen.err_war_check()
	gen.err_war_print()

	// for name, fnx in gen.table.fns {
	// 	println('-----function: ${name}\t${fnx.mod}\t${fnx.return_type}')
	// }
	// for imp in gen.table.imports {
	// 	println('-----import: ${imp}')
	// }
	// for mod in gen.table.modules {
	// 	println('-----module: ${mod}')
	// }
	// for name, idx in gen.table.type_idxs {
	// 	println('${idx}\t${name}')
	// }
	// println(gen.table.used_fns)

	mut e_count := 0
	for i, file in gen.files {
		// println('-----file: ${file.path}\t${file.mod}')
		e_count += if i != 0 { file.errors.len } else { 0 }
	}
	if e_count != 0 {	// clear out stream if any error exist
		gen.out = []
	}
	
	gen.out_replacements()
	return gen.out.join('\n')
}

// pub fn (mut gen Gen) find_all_source_files(source_path string) string {
// 	// main module builtin source file
// 	gen.source_paths << '${gen.transpiler_path}/ports/${gen.setup.value('path').string()}/api/builtin.c.v'
// 	// main source folder
// 	gen.add_sources(source_path)

// 	println('main source files:')	//  print source files
// 	for source in gen.source_paths {
// 		println('\t${source}')
// 	}

// 	// gen.parse_check_files()		// parse and check all the source files

// 	// // solve issue in Windows
// 	// if gen.files.len > gen.source_paths.len {
// 	// 	gen.files.pop()
// 	// }

// 	println('\n===== Top-down node analysis =====')
// 	temp_files := gen.files
// 	for i, file in temp_files {	// source folder
// 		gen.file_count = i
// 		gen.out << gen.ast_node(file) // starts from the main node (file)
// 	}
// }


