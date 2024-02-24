// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// hash_stmt: code generation for hash statements (C preprocessor).
fn (mut gen Gen) hash_stmt(node ast.HashStmt) string {
	// println('########### ${node.ct_conds} ###########')
	if node.kind == 'include' {
		if '#${node.val}\n' !in gen.c_preproc_cmds {
			gen.c_preproc_cmds << '#${node.val}\n'
		}
	} else {
		gen.c_preproc_cmds << '#${node.val}\n'
	}
	return ''
}