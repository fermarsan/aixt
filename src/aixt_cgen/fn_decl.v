
// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// import os
import v.ast

// fn_decl is the code generation function for the function declaration statement.
fn (mut gen Gen) fn_decl(node ast.FnDecl) []string {
	mut out := ['\n']
	mut attrs := ''
	mut ret_type := ''
	mut name := ''
	mut params := ''
	init_block := ''
	mut stmts := []string{}
	ret_stmt := ''
	if node.is_main {	// main function
		out << gen.fn_decl_main(node)
	} else {	
		// ignore function declaration without body and the enum init functions
		if node.no_body == false && !node.name.contains('__static__from') {
			module_short_name := node.mod.all_after_last('.')
			if node.short_name == 'init' { // module initialization functions
				gen.init_cmds << '${module_short_name}__init();'
			}
			gen.cur_fn = node.name
			mut nxc_task := false
			for a in node.attrs {
				attrs += '${a.name} '
				if a.name == 'task' { 
					nxc_task = true
				}
			}
			if nxc_task && gen.setup.backend == 'nxc' {
				name = '${node.short_name}'
			} else {
				ret_type = gen.setup.compiler_types[ gen.table.type_symbols[node.return_type].str()]
				ret_type = ret_type.replace('char []', 'char*') + ' '	// type
				name = '${module_short_name}__${node.short_name}'
			}
			if node.params.len != 0 {
				for pr in node.params {
					params += '${gen.ast_node(pr).join('')}, '
				}
				params = params#[..-2] 
			}
			for st in node.stmts {
				stmts << gen.ast_node(st).join('\n').split('\n')	// separate line by line
			}
			if attrs.contains('inline') && gen.setup.inline_as_c_macro {	// if inline functions as macros is wanted
				mut names := ''
				for param in node.params {
					names += '${param.name}, '
				}
				names = names#[..-2]
				if stmts.len == 1 {
					stmt := stmts.pop()#[..-1]	// remove the last ";"
					out << $tmpl('c_templates/fn_decl_as_macro.tmpl.c')#[..-1].replace('return', '')
				} else {
					out << $tmpl('c_templates/fn_decl_as_multi_macro.tmpl.c')#[..-1].replace('return', '')
				}
			} else {
				gen.definitions << $tmpl('c_templates/fn_prototype.tmpl.c')#[..-1].replace('inline ', '')	// generates the function's prototype
				out << $tmpl('c_templates/fn_decl.tmpl.c')#[..-1]
			}
		}
	}
	return out	
}

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
	mut ending := ''
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
			ending = '\nvoid loop(){\n}'
		}
		else{
			print('Invalid "Backend" in setup file.' )
		}
	}
	out << $tmpl('c_templates/fn_decl.tmpl.c')#[..-1]
	out << ending
	return out	
}