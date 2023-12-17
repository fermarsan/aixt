// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builder.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This file contains the functions to make a source code project in Aixt.

module aixt_build

import os
import toml
import v.ast
import v.pref
import aixt_cgen

pub fn transpile_file(path string, setup_file toml.Doc, aixt_path string) {
	mut c_gen := aixt_cgen.Gen{
		file: &ast.File{}
		table: ast.new_table()
		base_path: aixt_path
		out: ''
		includes: ''
		definitions: ''
		current_fn: 'global'
		main_loop_cmds:	''
		cond_assign: false
		level_cont: 0
		pref: &pref.Preferences{}
		setup: toml.Doc{}
	}

	c_gen.pref.is_script = true
	c_gen.pref.enable_globals = true
	c_gen.setup = setup_file

	// do the aliases replacement
	// mut source := os.read_file(path) or { 'Cannot read the file...' }	// read the source code
	// for alias in c_gen.setup.value('aliases').as_map().keys() { // replace aliases in source
	// 	source = source.replace(
	// 		alias,
	// 		(c_gen.setup.value('aliases').as_map()[alias] or {''}).string()
	// 	)
	// }
	// os.write_file('${os.dir(path)}/temp.v', source) or {}	// write the modified source code to a temporary file

	// mut transpiled := c_gen.gen('${os.dir(path)}/temp.v') // transpile Aixt (V) to C
	mut transpiled := c_gen.gen(path) // transpile Aixt (V) to C

	for alias in c_gen.setup.value('aliases').as_map().keys() { // replace aliases in the transpiled code
		transpiled = transpiled.replace(
			alias,
			(c_gen.setup.value('aliases').as_map()[alias] or {''}).string()
		)
	}

	// saves the output file
	output_ext := match c_gen.setup.value('backend').string() {
		'nxc' 		{ '.nxc' }
		'arduino'	{ '.ino' } 
		else 		{ '.c' }
	}
	mut output_path := path.replace('.aixt', output_ext)
	output_path = output_path.replace('.v', output_ext)
	// println('\n${output_path}\n')
	os.write_file(output_path, transpiled) or {}
}

pub fn compile_file(path string, setup_file toml.Doc) {

	cc := $if windows { // C compiler depending on the OS
		setup_file.value('cc_windows').string()
	} $else {
		setup_file.value('cc_linux').string()
	}

	flags := setup_file.value('cc_flags').string()

	// compiles the output file
	if setup_file.value('backend').string() == 'nxc' {
		println(os.execute('${cc} ${path}.nxc ${flags} ${path}').output)
	} else { 
		println(os.execute('${cc} ${path}.c ${flags} ${path}').output)
	}
}
