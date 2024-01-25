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

pub struct Gen {
mut:	
	file  			&ast.File  = unsafe { nil }
	table 			&ast.Table = unsafe { nil }
	transpiler_path string
	out   			string
	includes		string
	definitions		string
	current_fn		string
	main_loop_cmds	string
	// temps_cont	int
	level_cont		int
	// idents			[]ast.Ident
	idents			map[string] struct {
	mut:
		kind    	ast.IdentKind	
		typ			ast.Type
		// is_busy		bool
		elem_type	ast.Type
		len			int
	}
	type_names		[]string
pub mut:
	pref  			&pref.Preferences = unsafe { nil }
	setup 			toml.Doc
}

pub fn (mut gen Gen) gen(source_path string) string {
	// gen.temps_cont = 0
	gen.level_cont = 0
	gen.definitions = ''
	gen.includes = ''
	// gen.pref.is_script = true
	gen.file = parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
	mut checker_ := checker.new_checker(gen.table, gen.pref)
	checker_.check(mut gen.file)
	println(gen.table.type_symbols)
	println('\n\n===== Top-down node analysis =====\n')
	gen.out = gen.ast_node(gen.file) // starts from the main node (file)
	println('\n\n===== Symbol table =====\n')
	println('\n--file.global_scope')
	print('${gen.symbol_table(gen.file.global_scope)}')
	println('\n--file.scope')
	print('${gen.symbol_table(gen.file.scope)}')
	println('\n--file.scope.childern')
	for child in gen.file.scope.children {
		println('${gen.symbol_table(child)}')
	}

	// println(gen.file)

	// all := gen.file.scope.get_all_vars()
	// println(all)

	// for var in  {
	// 	println(var.name)
	// }

	gen.out_format()
	return gen.out
}