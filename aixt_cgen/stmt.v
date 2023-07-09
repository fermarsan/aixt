// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: stmt.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for statements.
module aixt_cgen

import v.ast
import v.token

fn (mut gen Gen) fn_decl(node ast.FnDecl) string {
	mut out := ''
	if node.is_main {
		out += if gen.setup.value('backend').string() == 'nxc' { 'task ' } else { '' }
		out += '${gen.setup.value('main_ret_type').string()} '
		out += 'main(${gen.setup.value('main_params').string()}) {\n'
		// println('fn stmts:\t${node.stmts}')
		for st in node.stmts {
			out += gen.ast_node(st)
			// println('fn stmt:\t${st}')
		}
		out += if gen.setup.value('main_ret_type').string() == 'int' { 'return 0;\n}' } else { '}' }
		out = if out[0] == ` ` { out[1..] } else { out }
	} else {
		for a in node.attrs {
			out += '${a.name} '
		}
		out += '${gen.setup.value(ast.new_table().type_symbols[node.return_type].str()).string()} ' // return type
		out += '${node.name.after('.')}('
		if node.params.len != 0 {
			for pr in node.params {
				println(pr.name)
				out += '${gen.ast_node(pr)}, '
			}
			out = out#[..-2] + ') {\n'
		} else {
			') {\n'
		}
		for st in node.stmts {
			out += gen.ast_node(st)
		}
		out += '}\n'
		out = if out[0] == ` ` { out[1..] } else { out }
	}
	return out
}

fn (mut gen Gen) assign_stmt(node ast.AssignStmt) string {
	mut out := ''
	for i in 0 .. node.left.len {
		var_type := gen.setup.value(ast.new_table().type_symbols[node.right_types[i]].str())
		if node.op == token.Kind.decl_assign { // in case of declaration
			if node.right[i].type_name() == 'v.ast.CastExpr' { // in case of casting expression
				out += if var_type.string() == 'char []' {
					'char ${gen.ast_node(node.left[i])}[] = ${gen.ast_node((node.right[i] as ast.CastExpr).expr)};\n'
				} else {
					'${var_type.string()} ${gen.ast_node(node.left[i])} = ${gen.ast_node((node.right[i] as ast.CastExpr).expr)};\n'
				}
			} else {
				out += if var_type.string() == 'char []' {
					'char ${gen.ast_node(node.left[i])}[] = ${gen.ast_node(node.right[i])};\n'
				} else {
					'${var_type.string()} ${gen.ast_node(node.left[i])} = ${gen.ast_node(node.right[i])};\n'
				}
			}
		} else { // for the rest of assignments
			out += '${gen.ast_node(node.left[i])} ${node.op} ${gen.ast_node(node.right[i])};\n'
		}
	}
	return out
}

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

fn (mut gen Gen) for_stmt(node ast.ForStmt) string {
	mut out := 'while('
	out += if node.is_inf { 'true) {\n' } else { '${gen.ast_node(node.cond)}) {\n' }
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	return out + '}\n'
}
