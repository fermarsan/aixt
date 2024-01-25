// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: for.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for all variations of the 'for' statement.
module aixt_cgen

import v.ast

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
	if node.high.type_name() == 'v.ast.EmptyExpr' { // in an array
		gen.level_cont++
		temp_name := '_t${gen.level_cont}'
		if temp_name !in gen.idents {
			gen.idents[temp_name] = struct { // add the temporal var
				kind: ast.IdentKind.variable
				typ: ast.Type(ast.Kind.int)
			}
			gen.definitions += 'int _t${gen.level_cont};\n'
		}
		out += 'for(int _t${gen.level_cont} = 0;'
		out += ' _t${gen.level_cont} < ${gen.idents[gen.ast_node(node.cond)].len};'
		out += ' _t${gen.level_cont}++) {\n'
		for st in node.stmts {
			out += gen.ast_node(st)
		}
		out = out.replace(node.val_var, '${gen.ast_node(node.cond)}[_t${gen.level_cont}]')
	} else { // in a range
		out += 'for(int ${node.val_var}=${gen.ast_node(node.cond)}; '
		out += '${node.val_var}<${gen.ast_node(node.high)}; ${node.val_var}++) {\n'
		for st in node.stmts {
			out += gen.ast_node(st)
		}
	}
	return out + '}\n'
}
