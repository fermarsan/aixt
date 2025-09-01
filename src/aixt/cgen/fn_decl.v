
// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

// import os
import v.ast

// fn_decl is the code generation function for the function declaration statement.
fn (mut gen Gen) fn_decl(node ast.FnDecl) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node.short_name} <<<<<<<<<<<<<<<<<<')
	// println('>>>>>>>>>>>>>>>>>> ${node.mod} <<<<<<<<<<<<<<<<<<')
	mut out := ['\n']
	mut attrs := if node.attrs.len == 0 { '' } else { node.attrs[0].name }
	mut ret, mut ret_type := '', ''
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
				if a.name == 'task' { 
					nxc_task = true
				}
			}
			// -------------------- NXC tasks --------------------
			if nxc_task && gen.setup.backend == 'nxc' {
				name = '${node.short_name}'
			// -------------------- regular functions and methods --------------------
			} else {
				ret, ret_type = gen.get_str_c_type(node.return_type, false)
				// ret_type = ret + ret_type.replace('string', 'char*') + ' '	// type
				ret_type = ret_type.replace('string', 'char*') + '${ret} '	// type
				// ret_type = ret_type.replace('.', '__')
				if node.is_method {		// methods
					_, mut struct_type := gen.get_str_c_type(node.params[0].typ, false)
					struct_type = struct_type.replace('.', '__')
					name = '${struct_type}_${node.name}'
				} else {				// regular  functions
					name = '${module_short_name}__${node.short_name}'
				}
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
			// -------------------- functions as C macros -------------------- 
			if attrs == 'as_macro' {	
				mut names := ''
				for param in node.params {
					names += '${param.name}, '
					// if param.typ.is_ptr() {
					// 	for mut stmt in stmts {
					// 		stmt = stmt.replace('${param.name}->', '${param.name}.')
					// 	}
					// }
				}
				names = names#[..-2]
				if stmts.len == 1 {
					mut stmt := stmts.pop()#[..-1]	// remove the last ";"
					if node.is_variadic {	// variable number of arguments
						stmt = stmt.replace('(${names})', '(__VA_ARGS__)')	
						names = '...'		
					}	
					out << $tmpl('c_templates/fn_decl_as_macro.tmpl.c')#[..-1].replace('return', '')
				} else {
					out << $tmpl('c_templates/fn_decl_as_multi_macro.tmpl.c')#[..-2].replace('return', '')
				}
			// ---------- functions as Interrupt Service Routines ----------
			} else if attrs.contains('_isr') {
				mut attr_arg := ''
				if node.attrs[0].has_arg {
					defined_const := gen.table.global_scope.find_const(node.attrs[0].arg) or { 
						&ast.ConstField {
							name: ''
						}
					}
					attr_arg = if defined_const.name != '' { 
						'_${defined_const.expr.str()}'  
					} else {
						'_${node.attrs[0].arg}'
					}
				} 
				gen.definitions.insert(0, '\nvoid (*ptr_${attrs}${attr_arg})(void);')
				gen.init_cmds << 'ptr_${attrs}${attr_arg} = ${name};'
				// isr_name := attrs.replace('_isr', '')
				// match gen.setup.backend {
				// 	'c' {
				// 		gen.init_cmds << 'ptr_${isr_name}_isr = ${name};'
				// 	}
				// 	'arduino' {
				// 		if isr_name == 'ext' {
				// 			pin_name := node.attrs[0].arg
				// 			pin := gen.table.global_scope.find_const(pin_name) or { panic(err) }
				// 			name = 'ext_isr_${pin.expr.str()}'
				// 			// '''#define enable_ext_irq_${node.attrs[0].arg.replace('.', '__')} \\
				// 			// attachInterrupt(digitalPinToInterrupt(_const_${node.attrs[0].arg.replace('.', '__')}), ${name}, _const_ext__${node.attrs[1].name})'''
				// 		} else {
				// 			gen.init_cmds << 'ptr_${isr_name}_isr = ${name};' 
				// 		}
				// 	}
				// 	else {
				// 		name = name
				// 	}
				// }
				attrs = ''
				out << $tmpl('c_templates/fn_decl.tmpl.c')#[..-1]
			// -------------------- regular functions --------------------
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
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
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