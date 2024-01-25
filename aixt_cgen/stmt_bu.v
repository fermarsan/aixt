// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: stmt.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for statements.
module aixt_cgen

import v.ast

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
	// println('${gen.setup.value('port').string()}')
	api_path := '${gen.transpiler_path}/ports/${gen.setup.value('path').string()}/api'
	if node.syms.len == 0 {
		gen.includes += '#include "${api_path}/${node.mod}.c"\n'
	} else {
		for s in node.syms {
			gen.includes += '#include "${api_path}/${node.mod}/${s.name}.c"\n'
		}
	}

	// for f in node.fields {
	// 	out += '${gen.ast_node(f)}'
	// }
	// println('------------${node.mod}------------')
	// println(node.alias)
	// println(node.syms)	
	return ''
}

fn (mut gen Gen) hash_stmt(node ast.HashStmt) string {
	if node.kind == 'include' {
		gen.includes += '#${node.val}\n'
	} else {
		gen.definitions += '#${node.val}\n'
	}
	return ''
}