
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
	gen.cur_fn = 'main'
	mut attrs := ''
	mut ret_type := ''
	mut name := 'main'
	mut params := ''
	init_block := '___initialization_block___'
	mut stmts := []string{}
	mut ret_stmt := ''
	for st in node.stmts {	// inner statements
		stmts << gen.ast_node(st).join('')
	}
	match gen.setup.backend {
		'c' {
			ret_type = gen.setup.main_ret_type
			params = gen.setup.main_params
			if ret_type == 'int' {	// return value 
				ret_stmt = 'return 0;'
			}
		}
		'nxc' {
			attrs = 'task'
		}
		'arduino' {
			ret_type = 'void'
			name = 'setup'
		}
		else{
			print('Invalid "Backend" in setup file.' )
		}
	}
	out << $tmpl('c_templates/fn_decl.c')#[..-1]
	return out	
}