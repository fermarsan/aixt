// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// infix_expr is the code generation function for 'infix' expressions (binary operations).
fn (mut gen Gen) infix_expr(node ast.InfixExpr) string {
	if node.left_type == ast.string_type_idx || node.right_type == ast.string_type_idx {
		match node.op.str() {
			'==' {
				gen.add_include('string.h')
				return '!strcmp(${gen.ast_node(node.left)}, ${gen.ast_node(node.right)})'
			} 
			'!=' {
				gen.add_include('string.h')
				return 'strcmp(${gen.ast_node(node.left)}, ${gen.ast_node(node.right)})'
			} 
			'+' {
				gen.add_include('string.h')
				gen.add_definition('char __temp_str[${gen.setup.value('string_default_len').int()}];')
				return 'strcat(strcpy(__temp_str, ${gen.ast_node(node.left)}), ${gen.ast_node(node.right)})'
			} 
			else {
				return ''
			}
		}
	} else {
		return '${gen.ast_node(node.left)} ${node.op} ${gen.ast_node(node.right)}'
	}
	println('XXXXXXXXXXXXX ${node.promoted_type} XXXXXXXXXXXXX')
	return ''
}