// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module main

import os
import v.token
import v.ast
import v.pref
import v.builder as v_builder
import aixt.setup
import aixt.builder as aixt_builder
import aixt.cgen


// transpile transpiles an Aixt project (single or multiple file) into C.
pub fn transpile(path string, project_setup setup.Setup) {

	// set de defines from the port's json file
	mut defines := ['']
	for define in project_setup.v_defines {
		defines << ['-d', define]
	}
	mut aixt_pref, _ := pref.parse_args_and_show_errors([], defines, true)
	aixt_pref.is_script = true
	aixt_pref.enable_globals = true
	aixt_pref.vmodules_paths = project_setup.api_paths
	// aixt_pref.experimental = true	// DISABLE for V compiler v0.4.9+ (avoid manual C functions declaration)

	// -------------------- creates the builder --------------------
	mut aixt_b := aixt_builder.Builder {
		Builder:	v_builder.new_builder(aixt_pref)
		setup:		project_setup
		aixt_path:	os.dir(os.executable())
	}
	aixt_b.table = ast.new_table()

	// parse source files
	aixt_b.parse_files_dir(path)
	
	aixt_b.sym_table_print()
	aixt_b.err_war_check()
	aixt_b.err_war_print()

	// --------------------creates the C code generator --------------------
	mut c_gen := cgen.Gen {
		Builder:			aixt_b
		// setup:				project_setup
		// aixt_path:			os.dir(os.executable())
		cur_scope: 			&ast.Scope{}
		cur_left:			ast.Nil{}
		cur_left_type:		0
		cur_op:				token.Kind.unknown
		cur_cond:			ast.Nil{}
		// imports: 		 	[]string{}
		source_paths: 		[]string{}
		out: 				[]string{}
		c_preproc_cmds:		[]string{}
		// api_mod_paths:		map[string][]string{}
		// lib_mod_paths:		map[string][]string{}
		include_paths:	    []string{}
		// macros: 			 []string{}
		definitions: 		[]string{}
		init_cmds:			[]string{}
		to_insert_lines:	[]string{}
		cur_fn: 			'main'
		file_count: 		0
		level_count:        0
		match_as_nested_if: false
		cpu_freq_defined:	false
	}

	// generates de C code
	mut transpiled := c_gen.gen(path) // transpile Aixt (V) to C

	if transpiled != '' {
		output_ext := match c_gen.setup.backend {
			'nxc' 		{ '.nxc' }
			'arduino'	{ '.ino' }
			else 		{ '.c' }
		}

		mut output_path := ''
		if os.is_file(path) {
			output_path = path.replace('.v', output_ext)
		} else {
			output_path = os.norm_path('${path}/main${output_ext}')
		}
		os.write_file(output_path, transpiled) or {}
	}

	aixt_b.err_war_print()
}