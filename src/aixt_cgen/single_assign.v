// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast
import v.token

// single_assign is the code generation function for single assignment statements.
// This works for:
// - only assignments `=`
// and
// - cumulative-assignments `+=`, `-=`, etc. 
fn (mut gen Gen) single_assign(left ast.Expr, left_type ast.Type, op token.Kind, right ast.Expr) []string {
	mut c_line := ''
	var_kind := gen.table.type_kind(left_type).str()
	left_expr := left
	match left_expr {
		ast.Ident {	// if it is a simple variable
			match var_kind {
				'array' {
					if gen.setup.value('fixed_size_arrays').bool() {
						panic('\n\nTranspiler Error:\nFor now dynamic-size arrays are not allowed.\n')
					}
				}
				'string' {
					match op.str() {
						'=' {
							gen.add_include('string.h')
							c_line += 'strcpy(${gen.ast_node(left).join('')}, ${gen.ast_node(right).join('')});'
						} 
						'+=' {
							gen.add_include('string.h')
							c_line += 'strcat(${gen.ast_node(left).join('')}, ${gen.ast_node(right).join('')});'
						}	
						else {
							panic('\n\nTranspiler Error:\n"${op.str()}" operator not supported for strings.\n')
						}
					}
				}
				else {
					c_line += '${gen.ast_node(left).join('')} ${op} ${gen.ast_node(right).join('')};'
				}
			} 
		} 
		else {
			c_line += '${gen.ast_node(left).join('')} ${op} ${gen.ast_node(right).join('')};'
		}
	}
	return [c_line]
}