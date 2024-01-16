// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: cgen.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This file contains the C code generation fucntions of the Aixt project.

module aixt_cgen

import v.ast
// import v.token
import v.pref
import v.parser
import v.checker
import toml

pub struct Gen {
mut:	
	file  			&ast.File  = unsafe { nil }
	table 			&ast.Table = unsafe { nil }
	base_path		string
	out   			string
	includes		string
	definitions		string
	current_fn		string
	main_loop_cmds	string
	cond_assign		bool
	// temps_cont	int
	level_cont		int
	idents			map[string] struct {
	mut:
		kind    	ast.IdentKind	
		typ			ast.Type
		// is_busy		bool
		elem_type	ast.Type
		len			int
	}
	types			[]string
pub mut:
	pref  			&pref.Preferences = unsafe { nil }
	setup 			toml.Doc
}

pub fn (mut gen Gen) gen(source_path string) string {
	// gen.temps_cont = 0
	gen.level_cont = 0
	gen.definitions = ''
	gen.includes = ''
	// gen.pref.is_script = true
	gen.file = parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
	// println('${'='.repeat(50)}\n${gen.file}${'='.repeat(50)}\n')
	mut checker_ := checker.new_checker(gen.table, gen.pref)
	checker_.check(mut gen.file)
	// gen.table.cur_fn.scope.children[0].objets['_i'] = 0
	// println('${gen.table.cur_fn.scope.children[0]}')
	// println('a' in gen.table.cur_fn.scope.children[0].objects)
	println('\n===== Top-down node analysis =====')
	gen.out = gen.ast_node(gen.file) // starts from the main node (file)
	println('\n===== Symbol table =====\n${gen.symbol_table()}')
	gen.out_format()
	return gen.out
}

fn (mut gen Gen) ast_node(node ast.Node) string {
	print('${node.type_name().after('v.ast.')} -> ')
	match node {
		ast.File {
			return gen.ast_file(node)
		}
		ast.Stmt {
			return gen.stmt(node)
		}
		ast.Expr {
			return gen.expr(node)
		}
		ast.ConstField {
			return gen.const_field(node)
		}
		ast.GlobalField {
			return gen.global_field(node)
		}
		ast.EnumField {
			return gen.enum_field(node)
		}
		ast.IfBranch { // statement block of "if" and "else" expressions
			return gen.if_branch(node)
		}
		ast.CallArg {
			return gen.call_arg(node)
		}
		ast.Param {
			return gen.param(node)
		}
		else {
			return ''
		} //'Error: Not defined node.\n' }
	}
}

fn (mut gen Gen) symbol_table() string {
	mut msg := ''
	for key, val in gen.idents {
		msg += '${val.kind} - ${key} - ${gen.table.type_kind(val.typ)}' + if val.len != 0 { 
			'[${val.len}] - ${gen.table.type_kind(val.elem_type)}\n' 
		} else {
			'\n'
		}
	}
	return msg
}

fn (mut gen Gen) out_format() {
	gen.out = gen.out.replace('___includes_block___', gen.includes)
	gen.out = gen.out.replace('___definitions_block___', gen.definitions)
	gen.out = gen.out.replace('\n\n\n;', '\n')
	gen.out = gen.out.replace('\n\n;', '\n---')
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
	temp = temp.replace('\t}', '}')
	gen.out = temp + '\n'
}


  


// creating settings.h
// ast.File {
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
