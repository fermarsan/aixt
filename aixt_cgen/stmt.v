// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: stmt.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for statements.
module aixt_cgen

import v.ast
import os

fn (mut gen Gen) expr_stmt(node ast.ExprStmt) string {
	return '${gen.ast_node(node.expr)};\n'
}

fn (mut gen Gen) return_stmt(node ast.Return) string {
	// Be Careful....... multiple values return
	return 'return ${gen.ast_node(node.exprs[0])};\n'
}

fn (mut gen Gen) branch_stmt(node ast.BranchStmt) string {
	return '${node.str()};\n'
}

fn (mut gen Gen) const_decl(node ast.ConstDecl) string {
	mut out := ''
	for f in node.fields {
		out += '${gen.ast_node(f)}'
	}
	return out
}

fn (mut gen Gen) global_decl(node ast.GlobalDecl) string {
	mut out := ''
	for f in node.fields {
		out += '${gen.ast_node(f)}'
	}
	return out
}

fn (mut gen Gen) import_stmt(node ast.Import) string {
	// println(gen.setup.value('api_path'))
	mut out := ''
	if node.syms.len == 0 {
		out += '#include "${gen.base_path}/${node.mod}.c"\n'
	} else {
		for s in node.syms {
			out += '#include "${gen.base_path}/${node.mod}__${s.name}.c"\n'
		}
	}

	// for f in node.fields {
	// 	out += '${gen.ast_node(f)}'
	// }
	// println('------------${node.mod}------------')
	// println(node.alias)
	// println(node.syms)	
	return out
}