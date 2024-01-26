// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: hash_stmt.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for hash statements (C preprocessor).
module aixt_cgen

import v.ast

fn (mut gen Gen) hash_stmt(node ast.HashStmt) string {
	if node.kind == 'include' {
		gen.incls += '#${node.val}\n'
	} else {
		gen.defs += '#${node.val}\n'
	}
	return ''
}