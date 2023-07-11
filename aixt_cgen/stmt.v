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
	// println('${gen.table.type_kind(node.right_types[0]).str()}')
	mut out := ''
	for i in 0 .. node.left.len {
		mut var_type := gen.table.type_kind(node.right_types[i]).str()
		// println('${var_type}')
		if node.op == token.Kind.decl_assign { // declaration
			match var_type {
				'array' {
					var_type = gen.table.type_kind((node.right[i] as ast.ArrayInit).elem_type).str()
					// println('${var_type}')
					out += '${gen.setup.value(var_type).string()} '	// array's element type
					out += '${gen.ast_node(node.left[i])}[${(node.right[i] as ast.ArrayInit).exprs.len}] = '
					out += '${gen.ast_node(node.right[i])};\n'
				}
				'string' {
					out += 'char ${gen.ast_node(node.left[i])}[] = '
					out += if node.right[i].type_name() == 'v.ast.CastExpr' {
						'${gen.ast_node((node.right[i] as ast.CastExpr).expr)};\n'
					} else {
						'${gen.ast_node(node.right[i])};\n'
					}
				}
				else {
					out += '${gen.setup.value(var_type).string()} ${gen.ast_node(node.left[i])} = '
					out += if node.right[i].type_name() == 'v.ast.CastExpr' {
						'${gen.ast_node((node.right[i] as ast.CastExpr).expr)};\n'
					} else {
						'${gen.ast_node(node.right[i])};\n'
					}
					gen.idents[gen.ast_node(node.left[i])] = struct {
						kind: ast.IdentKind.variable
						typ: node.right_types[i]
					}
					println(gen.idents)
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

fn (mut gen Gen) for_c_stmt(node ast.ForCStmt) string {
	mut out := 'for(${gen.ast_node(node.init)#[..-1]} ${gen.ast_node(node.cond)}; ${gen.ast_node(node.inc)#[..-2]}) {\n'
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	println('${out}')
	return out + '}\n'
}

fn (mut gen Gen) for_in_stmt(node ast.ForInStmt) string {
	mut out := ''
	if node.high.type_name() == 'v.ast.EmptyExpr' { // in array

		// println('${node.high}')
		//         if '__i' not in self.tempVars:
        //     self.tempVars.append('__i')
        //     self.topDecl.append('int __i;')
        // block = bl.replace(id1, '{}[__i]'.format(id2)) 
        // len_func = 'ArrayLen' if self.setup['nxc'] else 'sizeof'
        // s = 'for(__i = 0; __i < {}({}); __i++){}'.format(len_func, 
        //                                                  id2, 
        //                                                  block)
        // return s
	} else { // in a range
		out += 'for(int ${node.val_var}=${gen.ast_node(node.cond)}; '
		out += '${node.val_var}<${gen.ast_node(node.high)}; ${node.val_var}++) {\n'
	}
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	return out + '}\n'
}
