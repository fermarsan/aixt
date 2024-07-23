
// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import os
import v.ast

// fn_decl is the code generation function for the function declaration statement.
fn (mut gen Gen) fn_decl(node ast.FnDecl) []string {
	// println('------------------ ${node.name} ------------------------')
	mut out := ['\n']
	mut c_line := ''
	if node.is_main {	// main function
		out << gen.fn_decl_main(node)
	} else {		
		if node.no_body == false // ignore function declaration without body
		   && !node.name.contains('__static__from') {	// ignore enum init functions
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
					c_code = c_code.replace('${node.short_name}(', '${module_short_name}__${node.short_name}(')
					if !c_code.contains('#define') && !c_code.contains('irq__') {
						gen.definitions << c_code.all_before('{') + ';'		// generates the function's prototype
					}
					out << c_code
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
						gen.definitions << '#define ${c_line#[..-1]}_isr_exists'
						c_line = '${c_line#[..-1]}(${node.short_name})'
						gen.definitions << '${c_line} {'
						for st in node.stmts {
							gen.definitions << gen.ast_node(st)  	
						}
						gen.definitions << '}'
					} else {
						// println('##########${gen.table.type_symbols[node.return_type].str()}##########')
						if nxc_task {
							c_line += '${node.short_name}('
						} else {
							return_type := gen.setup.value(gen.table.type_symbols[node.return_type].str()).string()
							c_line += return_type.replace('char []', 'char*') + ' '	// type
							c_line += '${module_short_name}__${node.short_name}('
						}
						// out += '${node.name.replace('.', '__')}('
						if node.params.len != 0 {
							for pr in node.params {
								c_line += '${gen.ast_node(pr).join('')}, '
							}
							c_line = c_line#[..-2] + ')' 
							gen.definitions << c_line.replace('inline ', '') + ';\n'	// generates the function's prototype
						} else {
							c_line += ')' 
							gen.definitions << c_line.replace('inline ', '') + ';\n'	// generates the function's prototype
						}
						out << '${c_line} {'
						for st in node.stmts {
							out << gen.ast_node(st)  	
						}
						out << '}'
					}
				}
			}
		}
		// out = if out[0] == ` ` { out[1..] } else { out }
	}
	return out	
}