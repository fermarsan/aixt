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
	file  		&ast.File  = unsafe { nil }
	table 		&ast.Table = unsafe { nil }
	cur_scope	&ast.Scope = unsafe { nil }
	tr_path 	string
	out   		string
	incls		string
	defs		string
	cur_fn		string
	level_cont	int
pub mut:
	pref  		&pref.Preferences = unsafe { nil }
	setup 		toml.Doc
}

pub fn (mut gen Gen) gen(source_path string) string {
	// gen.temps_cont = 0
	gen.level_cont = 0
	gen.defs = ''
	gen.incls = ''
	// gen.pref.is_script = true
	gen.file = parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
	mut checker_ := checker.new_checker(gen.table, gen.pref)
	checker_.check(mut gen.file)
	// println(gen.table.type_symbols)
	println('\n\n===== Top-down node analysis =====\n')
	gen.out = gen.ast_node(gen.file) // starts from the main node (file)
	println('\n\n===== Symbol table =====\n')
	println('--file.global_scope\n')
	print('${gen.symbol_table(gen.file.global_scope)}')
	// println('\n--file.scope\n')
	// print('${gen.symbol_table(gen.file.scope)}')
	println('\n--file.scope.childern\n')
	for child in gen.file.scope.children {
		println('${gen.symbol_table(child)}')
	}
	println('${gen.file.errors.len} errors, ${gen.file.warnings.len} warnings.')
	for w in gen.file.warnings {
		println('Warning: ${w.message}')
	}
	for e in gen.file.errors {
		println('Error: ${e.message}')
	}
	gen.out_format()
	return gen.out
}