// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// it is governed by an MIT license (MIT)
// Copyright (c) 2023 Fernando Martínez Santa
module aixt_cgen

import v.ast
import v.token
import v.pref
import v.parser
import v.checker
import v.ast.walker
import toml

pub struct Gen {
mut:
	file  &ast.File  = unsafe { nil }
	table &ast.Table = unsafe { nil }
	out   string
pub mut:
	pref  &pref.Preferences = unsafe { nil }
	// setup &toml.Doc = unsafe { nil }
}

pub fn (mut gen Gen) gen(source_path string) string {
	// gen.pref.is_script = true
	gen.file = parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
	mut checker_ := checker.new_checker(gen.table, gen.pref)
	checker_.check(gen.file)
	walker.inspect(gen.file, unsafe { nil }, unsafe { gen.visit_gen })
	return gen.out
}

fn (mut gen Gen) visit_gen(node &ast.Node, data voidptr) bool {
	// println('\nHere..............\n')
	match node {
		ast.Expr {
			match node {
				ast.IfExpr { // basic shape of an "if" expression
					mut out := 'if(__cond__){\n__stmt__\n}\n'
					out += if node.has_else { 'else{\n__stmt__\n}\n' } else { '' }
					gen.out = gen.out.replace_once('__stmt__\n', out)
				}
				else {}
			}
		}
		ast.Stmt {
			match node {
				ast.FnDecl {
					if node.is_main {
						attrs := ''
						ret_type := if node.return_type == ast.void_type_idx {
							'void'
						} else {
							'int'
						}
						params := if node.params == [] { 'void' } else { 'int' }
						gen.out += '${attrs} ${ret_type} main(${params}) {\n${'__stmt__\n'.repeat(node.stmts.len)}}'
						gen.out = if gen.out[0] == ` ` { gen.out[1..] } else { gen.out }
					} else {
						// attrs	 := ''
						// ret_type := if node.return_type == ast.void_type_idx { 'void' } else { 'int' }
						// params 	 := if node.params == [] { 'void' } else { 'int' }
						// gen.out += '${attrs} ${ret_type} main(${params}) {\n${gen.temp_block_stmts(node.stmts.len)}}'
						// gen.out = if gen.out[0] == ` ` { gen.out[1..] } else { gen.out }
					}
				}
				ast.AssignStmt {
					mut assign := ''
					for i in 0 .. node.left.len {
						if node.op == token.Kind.decl_assign { // in case of declaration
							var_type := ast.new_table().type_symbols[node.right_types[i].idx()]
							assign += '${var_type} ${node.left[i]} = ${node.right[i]};\n'
						} else { // for the rest of assignments
							assign += '${node.left[i]} ${node.op} ${node.right[i]};\n'
						}
					}
					gen.out = gen.out.replace_once('__stmt__\n', assign)
				}
				else {}
			}
		}
		ast.IfBranch { // statements block of "if" and "else" expressions
			gen.out = gen.out.replace_once('__cond__', '${node.cond}')
			gen.out = gen.out.replace_once('__stmt__\n', '${'__stmt__\n'.repeat(node.stmts.len)}')
		}
		else {}
	}
	// println(gen.out + '\n' + '_'.repeat(60))	
	return true
}
