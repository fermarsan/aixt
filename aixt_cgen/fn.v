
// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: fn.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for the function declaration statement.
module aixt_cgen

import v.ast

fn (mut gen Gen) fn_decl(node ast.FnDecl) string {
	mut out := '\n'
	if node.is_main {	// main function
		gen.current_fn = 'main'
		match gen.setup.value('backend').string() {
			'c' {
				out += '${gen.setup.value('main_ret_type').string()} '	// return type
				out += 'main('	// main function 
				out += '${gen.setup.value('main_params').string()}) {\n'	// parameters	
				for c in gen.setup.value('initialization').array() {	// initialization lines
					out += '${c.string()}\n'    
				}		
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
				for c in gen.setup.value('initialization').array() {	// initialization lines
					out += '${c.string()}\n'    
				}		
				for st in node.stmts {	// inner statements
					out += gen.ast_node(st)
				}
				out += '}'
			}
			'arduino' {
				out += 'void setup() {\n'	// setup function
				for c in gen.setup.value('initialization').array() {	// initialization lines
					out += '${c.string()}\n'    
				}		
				for st in node.stmts {	// inner statements
					 stmt_str := gen.ast_node(st)
					 if stmt_str.starts_with('while(true) {\n') {
						out += '}\n\n'	// close the setup function
						out += stmt_str.replace('while(true)', 'void loop()')	// loop function
						break
					 } else {
						out += stmt_str
					 }
				}
				out += '}'
			}
		}
		out = if out[0] == ` ` { out[1..] } else { out }	// closing
	} else {
		gen.current_fn = node.name
		for a in node.attrs {
			out += '${a.name} '
		}
		out += '${gen.setup.value(ast.new_table().type_symbols[node.return_type].str()).string()} ' // return type
		out += '${node.name.after('.')}('
		if node.params.len != 0 {
			for pr in node.params {
				out += '${gen.ast_node(pr)}, '
				println(pr.name)
				var_name := '${gen.current_fn}.${pr.name}'
				gen.idents[var_name] = struct { // add the new symbol
					kind: ast.IdentKind.variable
					typ:  pr.typ	
				}
			}
			out = out#[..-2] + ') {\n'
		} else {
			') {\n'
		}
		for st in node.stmts {
			out += gen.ast_node(st)
		}
		out += '}\n'
		out = if out[0] == ` ` { out[1..] } else { out }
	}
	return out
}