// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: node.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for AST nodes.
module aixt_cgen

import v.ast

match node {
		ast.File {
		}
		// ast.Stmt {
		// }
		// ast.Expr {
		// println('${node.type_name().after('v.ast.')}:\t\t${node}')
		// 	match node {
		// 		ast.IfExpr { // basic shape of an "if" expression
		// 			mut out := 'if(__v.ast.Expr__){\n__v.ast.Stmt__}\n'
		// 			out += if node.has_else { 'else{\n__v.ast.Stmt__}\n' } else { '' }
		// 			gen.out = gen.out.replace_once('__v.ast.IfExpr__', out)
		// 		}
		// 		ast.CallExpr {
		// 			mut call_expr := '${node.name.after('.')}('
		// 			call_expr += if node.args.len != 0 { 
		// 				'__v.ast.CallArg__, '.repeat(node.args.len)#[..-2] + ')' 
		// 			} else {
		// 				')'
		// 			}
		// 			gen.out = gen.out.replace_once('__v.ast.CallExpr__', call_expr)
		// 		}
		// 		ast.ParExpr {
		// 			gen.out = gen.out.replace_once('__v.ast.ParExpr__', '(__${node.expr.type_name()}__)')
		// 			// println(node.expr)
		// 		}
		// 		ast.InfixExpr {
		// 			gen.out = gen.out.replace_once('__v.ast.InfixExpr__', 
		// 										   '__${node.left.type_name()}__ ${node.op} __${node.right.type_name()}__')
		// 		}
		// 		ast.PrefixExpr {
		// 			gen.out = gen.out.replace_once('__v.ast.PrefixExpr__', '${node.op}__${node.right.type_name()}__')
		// 		}
		// 		ast.PostfixExpr {
		// 			gen.out = gen.out.replace_once('__v.ast.PostfixExpr__', '__${node.expr.type_name()}__${node.op}')
		// 		}
		// 		ast.CastExpr {
		// 			var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())
		// 			gen.out = gen.out.replace_once('__v.ast.CastExpr__', '(${var_type.string()})(${node.expr})')
		// 		}
		// 		ast.Ident {
		// 			gen.out = gen.out.replace_once('__v.ast.Ident__', node.name)
		// 		}
		// 		ast.StringLiteral {
		// 			gen.out = gen.out.replace_once('__v.ast.StringLiteral__', '"${node.val}"')
		// 		}
		// 		ast.CharLiteral {
		// 			gen.out = gen.out.replace_once('__v.ast.CharLiteral__', "'${node.val}'")
		// 		}
		// 		ast.FloatLiteral {
		// 			gen.out = gen.out.replace_once('__v.ast.FloatLiteral__', node.val)
		// 		}
		// 		ast.IntegerLiteral {
		// 			out := if node.str().contains('0o') {	// if it is an octal literal
		// 				node.val.int().str() 				// turn it into decimal
		// 			} else {
		// 				node.val
		// 			}
		// 			gen.out = gen.out.replace_once('__v.ast.IntegerLiteral__', out)
		// 		}
		// 		ast.BoolLiteral {
		// 			gen.out = gen.out.replace_once('__v.ast.BoolLiteral__', node.val.str())
		// 		}
		// 		else {}
		// 	}
		// }
		ast.ConstField {
			mut assign := ''
			var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())			
			if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
				assign += if var_type.string() == 'char []' {
					'const char ${node.name.after('.')}[] = __${(node.expr as ast.CastExpr).expr.type_name()}__;\n'
				} else {
					'const ${var_type.string()} ${node.name.after('.')} = __${(node.expr as ast.CastExpr).expr.type_name()}__;\n'
				}								
			} else {
				assign += if var_type.string() == 'char []' {
					'const char ${node.name.after('.')}[] = __${node.expr.type_name()}__;\n'
				} else {
					'const ${var_type.string()} ${node.name.after('.')} = __${node.expr.type_name()}__;\n'
				}
			}
			gen.out += assign
		}
		ast.IfBranch { // statements block of "if" and "else" expressions
			gen.out = gen.out.replace_once('__v.ast.Expr__', '${node.cond}')
			gen.out = gen.out.replace_once('__v.ast.Stmt__', '${'__v.ast.Stmt__'.repeat(node.stmts.len)}')
		}
		ast.CallArg {	
			gen.out = gen.out.replace_once('__v.ast.CallArg__', '__${node.expr.type_name()}__')
		}
		ast.Param {
			var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())		
			gen.out = gen.out.replace_once('__v.ast.Param__', '${var_type.string()} ${node.name}')
		}
		else {}
	}
	// println(gen.out + '\n' + '_'.repeat(60))	
	return true
}

fn (mut gen Gen) out_format() {
	gen.out = gen.out.replace('}\n;', '}')
	mut temp := ''
	mut ind_count := 0
	for c in gen.out {
		match rune(c) {
			`\n` {
				temp += '\n' + '\t'.repeat(ind_count)
			}
			`{` {
				ind_count++
				temp += rune(c).str()
			}
			`}` {
				ind_count--
				temp += rune(c).str()
			}
			else {
				temp += rune(c).str()
			}
		}
	}