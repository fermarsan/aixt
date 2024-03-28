// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_build

import os
import toml
import v.ast
import v.pref
import aixt_cgen

// transpile_file transpiles an Aixt source code into C.
pub fn transpile_file(path string, setup_file toml.Doc, aixt_path string) {
	mut c_gen := aixt_cgen.Gen{
		files: 				[]&ast.File{}
		table: 				ast.new_table()
		cur_scope: 			&ast.Scope{}
		transpiler_path:	aixt_path
		source_paths: 		[]string{}
		out: 				''
		c_preproc_cmds:		[]string{}	
		// includes: 		[]string{}	
		// macros: 			[]string{}	
		definitions: 		[]string{}	
		init_cmds:			''
		cur_fn: 			'main'
		file_count: 		0
		level_cont: 		0
		pref:	 			&pref.Preferences{}
		setup: 				setup_file
	}

	c_gen.pref.is_script = true
	c_gen.pref.enable_globals = true
	

	// println('\n\n+++++++${path}++++++++\n\n')
	mut transpiled := c_gen.gen(path) // transpile Aixt (V) to C

	if transpiled != '' {
		for alias in c_gen.setup.value('aliases').as_map().keys() { // replace aliases in the transpiled code
			transpiled = transpiled.replace(
				alias,
				(c_gen.setup.value('aliases').as_map()[alias] or {''}).string()
			)
		}

		output_ext := match c_gen.setup.value('backend').string() {
			'nxc' 		{ '.nxc' }
			'arduino'	{ '.ino' } 
			else 		{ '.c' }
		}

		mut output_path := ''
		if os.is_file(path) {
			output_path = path.replace('.aixt', output_ext)
			output_path = output_path.replace('.v', output_ext)
		} else {
			output_path = '${path}/main${output_ext}'
		}
		os.write_file(output_path, transpiled) or {}
	}
}
