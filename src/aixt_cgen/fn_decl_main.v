
// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// import os
import v.ast

// fn_decl_main is the code generation function for the main function declaration.
fn (mut gen Gen) fn_decl_main(node ast.FnDecl) []string {
	// println('------------------ ${node.name} ------------------------')
	mut out := []string{}
	mut c_line := ''
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
	return out	
}