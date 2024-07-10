// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast
import os

// hash_stmt: code generation for hash statements (C preprocessor).
fn (mut gen Gen) hash_stmt(node ast.HashStmt) []string {
	// println('########### ${node.ct_conds} ###########')
	if node.kind == 'include' {
		if node.val.contains('<') && node.val.contains('>') {	// if it is a standard header
			if '#${node.val}' !in gen.c_preproc_cmds {
				gen.c_preproc_cmds << '#${node.val}'
			}
		} else {	// if it is a custom header
			c_file_name := node.main.replace('"', '')
			c_file_path := '${os.dir(node.source_file)}/${c_file_name}'
			c_lines := os.read_lines(c_file_path) or { panic(err) }
			gen.definitions << c_lines
		}
	} else {
		panic('Hash statement #${node.val} not supported.')
	}
	return [] if gen.code_gen else []
}