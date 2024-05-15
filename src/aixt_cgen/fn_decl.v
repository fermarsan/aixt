
// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import os
import v.ast

// fn_decl is the code generation function for the function declaration statement.
fn (mut gen Gen) fn_decl(node ast.FnDecl) []string {
	// println(gen.cur_scope.children[0])
	mut out := ['\n']
	mut c_line := ''
	if node.is_main {	// main function
		gen.cur_fn = 'main'
		match gen.setup.value('backend').string() {
			'c' {
				c_line += '${gen.setup.value('main_ret_type').string()} '	// return type
				c_line += 'main('	// main function 
				out << c_line + '${gen.setup.value('main_params').string()}) {'	// parameters	
				out << '___initialization_block___'	// initialization function	
				for st in node.stmts {	// inner statements
					out << gen.ast_node(st)
				}
				out << if gen.setup.value('main_ret_type').string() == 'int' {	// return value 
					['return 0;', '}'] 
				} else { 
					['}']
				}
			}
			'nxc' {
				out << 'task main() {'	// main task
				out << '___initialization_block___'	// initialization function			
				for st in node.stmts {	// inner statements
					out << gen.ast_node(st)
				}
				out << '}'
			}
			'arduino' {
				out << 'void setup() {'	// setup function	
				out << '___initialization_block___'	// initialization function	
				for st in node.stmts {	// inner statements
					 stmt_str := '${gen.ast_node(st).join('')}'
					 if stmt_str.starts_with('while(true) {\n') {
						out << ['}', '']	// close the setup function
						out << stmt_str#[..-2].replace('while(true)', 'void loop()')	// loop function
						break
					 } else {
						out << stmt_str
					 }
				}
				out << '}'
			}
			else{
				print('Invalid "Backend" in setup file.' )
			}
		}
		// out = if out[0] == ` ` { out[1..] } else { out }	// closing
	} else {
		// println('## fn name: ${node.name} ##')
		// println("+++++++++++++++\n${node.short_name}\n+++++++++++++++")
		// println("+++++++++++++++\n${node.mod}\n+++++++++++++++")
		module_short_name := node.mod.all_after_last('.')
		if node.short_name == 'init' { // module initialization functions
			gen.init_cmds << '${module_short_name}__init();'
		}
		match node.language {
			.c {				// for C.functions()
				c_file_path := os.dir(node.file) + '/${node.short_name}.c'
				mut c_code := os.read_file(c_file_path) or { panic(err) }
				out << c_code.replace('${node.short_name}(', '${module_short_name}__${node.short_name}(')
			}
			else {				//for regular functions
				gen.cur_fn = node.name
				mut nxc_task := false
				mut irq := false
				for a in node.attrs {
					c_line += '${a.name} '
					if a.name.contains('irq_') {
						irq = true
					} else if a.name == 'task' { 
						nxc_task = true
					}
				}
				if irq {
					c_line = '${c_line#[..-1]}(${node.short_name})'
				} else {
					// println('##########${gen.table.type_symbols[node.return_type].str()}##########')
					if nxc_task {
						c_line += '${node.short_name}('
					} else {
						c_line += gen.setup.value(gen.table.type_symbols[node.return_type].str()).string() + ' '
						c_line += '${module_short_name}__${node.short_name}('
					}
					// out += '${node.name.replace('.', '__')}('
					if node.params.len != 0 {
						for pr in node.params {
							c_line += '${gen.ast_node(pr).join('')}, '
						}
						c_line = c_line#[..-2] + ')' 
						// gen.definitions << out + ';\n'	// generates the function's prototype
					} else {
						c_line += ')' 
						// gen.definitions << out + ';\n'	// generates the function's prototype
					}
				}
				out << '${c_line} {'
				for st in node.stmts {
					out << gen.ast_node(st)  	
				}
				out << '}'
			}
		}
		// out = if out[0] == ` ` { out[1..] } else { out }
	}
	return out	
}