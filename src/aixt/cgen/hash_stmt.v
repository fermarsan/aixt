// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast
import os
import regex

// hash_stmt: code generation for hash statements (C preprocessor).
fn (mut gen Gen) hash_stmt(node ast.HashStmt) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	// println('########### ${node.ct_conds} ###########')
	mut out := []string{}
	if node.kind == 'include' {
		if node.val.contains('<') && node.val.contains('>') {	// if it is a standard header
			if '#${node.val}' !in gen.c_preproc_cmds {
				gen.c_preproc_cmds << '#${node.val}'
			}
		} else {	// if it is a custom header
			c_file_name := node.main.replace('"', '')
			c_file_path := os.dir(node.source_file) + os.path_separator + c_file_name
			// println('>>>>>>>>>>>>>>>>>> ${c_file_path} <<<<<<<<<<<<<<<<<<')
			// for .c files copy the code inside to the output
			if c_file_name.ends_with('.c') {
				mut c_lines := os.read_lines(c_file_path) or { panic(err) }
				// add initial new-line	
				c_lines.prepend('\n')
				// delete initial tabs	
				mut re := regex.regex_opt('\n[ \t]+') or { panic(err) }
				c_lines_2 := re.replace(c_lines.join('\n'), '\n')
				if c_lines_2.contains('_IRQ_') {	// if there is an IRQ definition
					gen.definitions.insert(0, c_lines_2)
				} else {	
					gen.definitions << re.replace(c_lines.join('\n'), '\n')
				}
				// add final new-line	
				gen.definitions << '\n'
			// for .h/.hpp files copy them to the output folder including its correspondent .c or .cpp 
			} else if c_file_name.ends_with('.h') || c_file_name.ends_with('.hpp') {
				gen.definitions << '#include "${c_file_name}"'
				gen.include_paths << c_file_path
				c_path := c_file_path.replace('.hpp', '.c').replace('.h', '.c')
				if os.exists(c_path) {
					gen.include_paths << c_path
				}
				cpp_path := c_file_path.replace('.hpp', '.cpp').replace('.h', '.cpp')
				if os.exists(cpp_path) {
					gen.include_paths << cpp_path
				}
				// println('>>>>>>>>>>>>>>>>>> ${gen.include_paths} <<<<<<<<<<<<<<<<<<')
			}
		}
	} else {
		panic('Hash statement #${node.val} not supported.')
	}
	return out
}