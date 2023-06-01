// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

module cemb_gen

import v.ast
import v.ast.walker

__global (
	attr		string
	ret_type	string
	params		string
	stmt_list	[]string
)

pub fn cgen(file &ast.File) string {
	walker.inspect(file, 
			       unsafe { nil }, 
				   unsafe { fn (node &ast.Node, data voidptr) bool {
		match node {
			ast.Stmt {
				match node {
					ast.FnDecl {
						if node.is_main {
							attr = ''
							ret_type = if node.return_type == ast.void_type_idx { 'void' } else { 'int' }
							params = if node.params == [] { 'void' } else { 'int' }
						}
					}
					ast.AssignStmt {
						for i in 0..node.left.len {
							stmt_list << '${node.left[i]} ${node.op} ${node.right[i]}\n'
						}
						return false
					}
					else{} 
				}
			}
			else {}
		}	
		// println(node)		
		return true
	}})

	mut output := '${attr} ${ret_type} main(${params}) {\n${stmt_list.join('\n')}\n}'
	output = if output[0] == ` ` { output[1..] } else { output } 
	// println(output)
	return output
}