
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
	mut stmts := []string{}
	name := 'main'
	gen.cur_fn = 'main'
	match gen.setup.value('backend').string() {
		'c' {
			attrs := ''
			ret_type := gen.setup.value('main_ret_type').string()
			params := gen.setup.value('main_params').string()
			for st in node.stmts {	// inner statements
				stmts << gen.ast_node(st).join('')
			}
			ret_stmt := if ret_type == 'int' {	// return value 
				'return 0;'
			} else { 
				''
			}
			out << $tmpl('c_templates/fn_decl.c')#[..-1]
		}
		'nxc' {
			attrs := 'task'
			ret_type := ''
			params := ''			
			for st in node.stmts {	// inner statements
				stmts << gen.ast_node(st).join('')
			}
			ret_stmt := ''
			out << $tmpl('c_templates/fn_decl.c')#[..-1]
		}
		'arduino' {
			mut loop := ''
			for st in node.stmts {	// inner statements
				stmt_str := gen.ast_node(st).join('')
				if stmt_str.starts_with('while(true) {\n') {
					loop = stmt_str#[..-2].replace('while(true)', 'void loop()')	// loop block
				} else {
					stmts << stmt_str
				}
			}
			out << $tmpl('c_templates/fn_main.ino')#[..-1]
		}
		else{
			print('Invalid "Backend" in setup file.' )
		}
	}
	return out	
}