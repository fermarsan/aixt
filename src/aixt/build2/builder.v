// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT

// Description: This file contains the C code generation functions of the Aixt.
module build2

import aixt.setup
import v.ast
import v.token
import v.pref
import v.parser
import v.checker
import os

// Gen is the struct that defines all the necessary data for the code generation
pub struct Gen {
pub mut:
// mut:
	files          		[]&ast.File
	table          		&ast.Table = unsafe { nil }
	cur_scope      		&ast.Scope = unsafe { nil }
	cur_left			ast.Expr
	cur_left_type  		ast.Type
	cur_op		   		token.Kind
	cur_cond       		ast.Expr
	aixt_path		string
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
// pub mut:
	pref 				&pref.Preferences = unsafe { nil }
	setup				setup.Setup
}