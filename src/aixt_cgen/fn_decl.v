
// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// fn_decl is the code generation function for the function declaration statement.
fn (mut gen Gen) fn_decl(node ast.FnDecl) string {
	// println(gen.cur_scope.children[0])
	mut out := '\n'
	if node.is_main {	// main function
		gen.cur_fn = 'main'
		match gen.setup.value('backend').string() {
			'c' {
				out += '${gen.setup.value('main_ret_type').string()} '	// return type
				out += 'main('	// main function 
				out += '${gen.setup.value('main_params').string()}) {\n'	// parameters	
				// for c in gen.setup.value('initialization').array() {	// initialization lines
				// 	out += '${c.string()}\n'    
				// }
				out += 'main__init();\n'	// initialization function	
				for st in node.stmts {	// inner statements
					out += gen.ast_node(st)
				}
				out += if gen.setup.value('main_ret_type').string() == 'int' {	// return value 
					'return 0;\n}' 
				} else { 
					'}' 
				}
			}
			'nxc' {
				out += 'task main() {\n'	// main task
				// for c in gen.setup.value('initialization').array() {	// initialization lines
				// 	out += '${c.string()}\n'    
				// }
				out += 'main__init();\n'	// initialization function			
				for st in node.stmts {	// inner statements
					out += gen.ast_node(st)
				}
				out += '}'
			}
			'arduino' {
				out += 'void setup() {\n'	// setup function
				// for c in gen.setup.value('initialization').array() {	// initialization lines
				// 	out += '${c.string()}\n'    
				// }		
				out += 'main__init();\n'	// initialization function	
				for st in node.stmts {	// inner statements
					 stmt_str := gen.ast_node(st)
					 if stmt_str.starts_with('while(true) {\n') {
						out += '}\n\n'	// close the setup function
						out += stmt_str#[..-2].replace('while(true)', 'void loop()')	// loop function
						break
					 } else {
						out += stmt_str
					 }
				}
				out += '}'
			}
			else{
				print('Invalid "Backend" in setup file.' )
			}
		}
		out = if out[0] == ` ` { out[1..] } else { out }	// closing
	} else {
		gen.cur_fn = node.name
		println('## fn name: ${node.name} ##')
		for a in node.attrs {
			out += '${a.name} '
		}
		// println('##########${gen.table.type_symbols[node.return_type].str()}##########')
		out += '${gen.setup.value(gen.table.type_symbols[node.return_type].str()).string()} ' // return type
		// out += '${node.name.replace('.', '__')}('
		out += '${node.mod.all_after_last('.')}__${node.short_name}('
		if node.params.len != 0 {
			for pr in node.params {
				out += '${gen.ast_node(pr)}, '
				println(pr.name)
				// var_name := '${gen.cur_fn}.${pr.name}'
			}
			out = out#[..-2] + ')' 
			gen.definitions << out + ';\n'	// generates the function's prototype
			out += ' {\n'
		} else {
			out += ')' 
			gen.definitions << out + ';\n'	// generates the function's prototype
			out += ' {\n'
		}
		for st in node.stmts {
			out += gen.ast_node(st)
		}
		
		out += if node.name == 'main.init' {
			'___initialization_block___\n}\n'
		} else {
			'}\n'
		}
		out = if out[0] == ` ` { out[1..] } else { out }
	}
	return out	
}