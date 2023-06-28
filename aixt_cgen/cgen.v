// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: cgen.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This file contains the C code generation fucntions of the Aixt project.

module aixt_cgen

// import os 
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
	setup toml.Doc //= unsafe { nil }
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
	println(node.type_name())
	// println(gen.file.path)
	match node {
		ast.File {
			// base_path := os.dir(gen.file.path)
			// // println(base_path)
			// mut out_settings := os.create('${base_path}/settings.h') or {	// creates the settings.h file
        	// 	println('Failed to create file')			// from setup.toml
        	// 	return false
    		// }
			// defer { out_settings.close() }

            // mut s := '#ifndef _SETTINGS_H_\n#define _SETTINGS_H_\n\n#include "api/builtin.h"\n'
			// // println(gen.setup.value('headers').array())
            // for h in gen.setup.value('headers').array() {			// append the header files
            //     s +=  if h.string() != '' { '#include <${h.string()}>\n' } else { '' }
			// }
            // s += '\n'
            // for m in gen.setup.value('macros').array() { 			// append the macros
            //     s += if m.string() != '' { '#define ${m.string()}\n' } else { '' }
			// }
            // s += '\n'
            // for c in gen.setup.value('configuration').array() {		// append the configuration lines
            //     s += '${gen.setup.value('config_operator').string()} ${c.string()}\n'    
			// }
            // s += '\n#endif  //_SETTINGS_H_'
            // out_settings.write_string(s) or {
        	// 	println('Failed to write file')
        	// 	return false
    		// }

            gen.out = '// Aixt project ('
            gen.out += if gen.setup.value('backend').string() == 'nxc' { 'NXC ' }  else { 'C ' }
            gen.out += 'generated code)\n// Device = ${gen.setup.value('device').string()}'
			gen.out += '\n// Board = ${gen.setup.value('board').string()}\n\n' 

            for h in gen.setup.value('headers').array() {			// append the header files
                gen.out +=  if h.string() != '' { '#include <${h.string()}>\n' } else { '' }
			}
            gen.out += '\n'
            // gen.out += '#include "api/builtin.h"\n'
            for m in gen.setup.value('macros').array() { 			// append the macros
                gen.out += if m.string() != '' { '#define ${m.string()}\n' } else { '' }
			}
            gen.out += '\n'
            for c in gen.setup.value('configuration').array() {		// append the configuration lines
                gen.out += '${gen.setup.value('config_operator').string()} ${c.string()}\n'    
			}

            // gen.out += if gen.setup.value('backend').string() != 'nxc' { '#include "../../settings.h"\n\n' } else {''}
            // s += '// ' + self.moduleDef + '\n'  // module definition
            // s += self.includes + '\n'           // user defined headers files
            // for td in self.topDecl:
            //     s += '{}\n'.format(td) #top level declarations      
            // if not self.main:       #adds the main function structure if not exist
            //     s += 'task' if gen.setup.value('nxc'] else ''
            //     s += gen.setup.value('main_ret_type'] if gen.setup.value('main_ret_type'] != 'none' else ''
            //     s += ' main('
            //     s += gen.setup.value('main_params'] if gen.setup.value('main_params'] != 'none' else ''
            //     s += ') {' 
            //     for i in gen.setup.value('initialization']:
            //         s += i + '\n' if i != '' else ''
            //     s += '\n\t'
            //     s += self.transpiled.replace('\n','\n\t')[:-1]
            //     s += 'return 0;\n}' if gen.setup.value('main_ret_type'] == 'int' else '}' 
            // else:
            //     s += self.transpiled
            // # s = s.replace('};','}')
            // outText.write(s) 
		}
		ast.Expr {
		println(node.type_name())
			match node {
				ast.IfExpr { // basic shape of an "if" expression
					mut out := 'if(__cond__){\n__stmt__\n}\n'
					out += if node.has_else { 'else{\n__stmt__\n}\n' } else { '' }
					gen.out = gen.out.replace_once('__stmt__\n', out)
				}
				ast.InfixExpr {
					gen.out = gen.out.replace_once('__v.ast.InfixExpr__', 
												   '__${node.left.type_name()}__ ${node.op} __${node.right.type_name()}__')
				}
				ast.PrefixExpr {
					gen.out = gen.out.replace_once('__v.ast.PrefixExpr__', '${node.op}${node.right}')
				}
				ast.PostfixExpr {
					gen.out = gen.out.replace_once('__v.ast.PostfixExpr__', '${node.expr}${node.op};')
				}
				ast.CastExpr {
					var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())
					gen.out = gen.out.replace_once('__v.ast.CastExpr__', '(${var_type.string()})(${node.expr})')
				}
				ast.Ident {
					gen.out = gen.out.replace_once('__v.ast.Ident__', node.name)
				}
				ast.StringLiteral {
					gen.out = gen.out.replace_once('__v.ast.StringLiteral__', '"${node.val}"')
				}
				ast.CharLiteral {
					gen.out = gen.out.replace_once('__v.ast.CharLiteral__', "'${node.val}'")
				}
				ast.FloatLiteral {
					gen.out = gen.out.replace_once('__v.ast.FloatLiteral__', node.val)
				}
				ast.IntegerLiteral {
					out := if node.str().contains('0o') {	// if it is an octal literal
						node.val.int().str() 				// turn it into decimal
					} else {
						node.val
					}
					gen.out = gen.out.replace_once('__v.ast.IntegerLiteral__', out)
				}
				ast.BoolLiteral {
					gen.out = gen.out.replace_once('__v.ast.BoolLiteral__', node.val.str())
				}
				else {}
			}
		}
		ast.Stmt {
			print('${node.type_name()} - ')
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
						gen.out += if attrs != '' { '${attrs} ' } else { '' }
						gen.out += '${ret_type} main(${params}) {\n${'__stmt__\n'.repeat(node.stmts.len)}}'
						gen.out = if gen.out[0] == ` ` { gen.out[1..] } else { gen.out }
					} else {

					}
				}
				ast.AssignStmt {
					mut assign := ''
					for i in 0 .. node.left.len {
						// println(node.right[i])
						var_type := gen.setup.value(ast.new_table().type_symbols[node.right_types[i]].str())
						// println('\n\t${var_type.string()}')
						if node.op == token.Kind.decl_assign { // in case of declaration
							if node.right[i].type_name() == 'v.ast.CastExpr' {	// in case of casting expression
								assign += if var_type.string() == 'char []' {
									'char __${node.left[i].type_name()}__[] = ${(node.right[i] as ast.CastExpr).expr};\n'
								} else {
									'${var_type.string()} __${node.left[i].type_name()}__ = ${(node.right[i] as ast.CastExpr).expr};\n'
								}								
							} else {
								assign += if var_type.string() == 'char []' {
									'char __${node.left[i].type_name()}__[] = __${node.right[i].type_name()}__;\n'
								} else {
									'${var_type.string()} __${node.left[i].type_name()}__ = __${node.right[i].type_name()}__;\n'
								}
							}
						} else { // for the rest of assignments
							assign += '__${node.left[i].type_name()}__ ${node.op} __${node.right[i].type_name()}__;\n'
						}
					}
					gen.out = gen.out.replace_once('__stmt__\n', assign)
				}
				ast.ExprStmt {
					gen.out = gen.out.replace_once('__stmt__\n', '__${node.expr.type_name()}__\n')
				}
				else {}
			}
		}
		ast.ConstField {
			mut assign := ''
			var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())			
			if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
				assign += if var_type.string() == 'char []' {
					'const char ${node.name.after('.')}[] = ${(node.expr as ast.CastExpr).expr};\n'
				} else {
					'const ${var_type.string()} ${node.name.after('.')} = ${(node.expr as ast.CastExpr).expr};\n'
				}								
			} else {
				assign += if var_type.string() == 'char []' {
					'const char ${node.name.after('.')}[] = __${node.expr.type_name()}__;;\n'
				} else {
					'const ${var_type.string()} ${node.name.after('.')} = __${node.expr.type_name()}__;\n'
				}
			}
			gen.out += assign
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

