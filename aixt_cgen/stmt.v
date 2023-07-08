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

fn (mut gen Gen) fn_decl(node ast.FnDecl) {
	if node.is_main {
		gen.out += if gen.setup.value('backend').string() == 'nxc' { 'task ' } else { '' }
		gen.out += '${gen.setup.value('main_ret_type').string()} '
		gen.out += 'main(${gen.setup.value('main_params').string()}) {\n'
		for st in node.stmts {
			gen.ast_node(st)
		}
		gen.out += if gen.setup.value('main_ret_type').string() == 'int' { 'return 0;\n}' } else { '}' }
		gen.out = if gen.out[0] == ` ` { gen.out[1..] } else { gen.out }
	} else {
		for a in node.attrs {
			gen.out += '${a.name} '
		}
		gen.out += '${gen.setup.value(ast.new_table().type_symbols[node.return_type].str()).string()} '	// return type
		gen.out += '${node.name.after('.')}('
		gen.out += if node.params.len != 0 { 
			'${'__v.ast.Param__, '.repeat(node.params.len)}'#[..-2] + ') {\n' 
		} else {
			') {\n'
		}
		gen.out += '${'__v.ast.Stmt__'.repeat(node.stmts.len)}}\n'
		gen.out = if gen.out[0] == ` ` { gen.out[1..] } else { gen.out }
	}
}

fn (mut gen Gen) assign_stmt(node ast.AssignStmt) {
	for i in 0 .. node.left.len {
		var_type := gen.setup.value(ast.new_table().type_symbols[node.right_types[i]].str())
		if node.op == token.Kind.decl_assign { // in case of declaration
			if node.right[i].type_name() == 'v.ast.CastExpr' {	// in case of casting expression
				gen.out += if var_type.string() == 'char []' {
					'char __${node.left[i].type_name()}__[] = __${(node.right[i] as ast.CastExpr).expr.type_name()}__;\n'
				} else {
					'${var_type.string()} __${node.left[i].type_name()}__ = __${(node.right[i] as ast.CastExpr).expr.type_name()}__;\n'
				}								
			} else {
				gen.out += if var_type.string() == 'char []' {
					'char __${node.left[i].type_name()}__[] = __${node.right[i].type_name()}__;\n'
				} else {
					'${var_type.string()} __${node.left[i].type_name()}__ = __${node.right[i].type_name()}__;\n'
				}
			}
		} else { // for the rest of assignments
			gen.out += '__${node.left[i].type_name()}__ ${node.op} __${node.right[i].type_name()}__;\n'
		}
		gen.ast_node(node.left[i])
		gen.ast_node(node.right[i])
	}
}

fn (mut gen Gen) expr_stmt(node ast.ExprStmt) {
	// println('__${node.expr.type_name()}__')
	gen.out = gen.out.replace_once('__v.ast.Stmt__', '__${node.expr.type_name()}__;\n')
}

fn (mut gen Gen) return_stmt(node ast.Return) {
	// Be Careful....... multiple values return
	gen.out = gen.out.replace_once('__v.ast.Stmt__', 'return __${node.exprs[0].type_name()}__;\n')
}

fn (mut gen Gen) branch_stmt(node ast.BranchStmt) {
	gen.out = gen.out.replace_once('__v.ast.Stmt__', '${node.str()};\n')
}

fn (mut gen Gen) for_stmt(node ast.ForStmt) {
	// println('===${node}===')
	// println('===${node.children()}===')
	println('${node.cond.type_name()}')
	mut out := 'while('
	out += if node.is_inf { 'true) {\n' } else { '__${node.cond.type_name()}__) {\n' }
	out += '${'__v.ast.Stmt__'.repeat(node.stmts.len)}}\n'
	gen.out = gen.out.replace_once('__v.ast.Stmt__', out)
	// if !node.is_inf {
	// 	println('--for condition--')
	// 	os.write_file('temp.v', node.cond.str()) or {}
	// 	// temp_file := parser.parse_file('temp.v', gen.table, .skip_comments, gen.pref)
	// 	// walker.inspect(temp_file, unsafe { nil }, unsafe { gen.visit_gen })
	// 	// println('$temp_file')
	// }
}