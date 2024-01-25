// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: infix_expr.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for 'infix' expressions (binary operations).
module aixt_cgen

import v.ast

fn (mut gen Gen) infix_expr(node ast.InfixExpr) string {
	lvar_type := gen.idents['${gen.current_fn}.${node.left.str()}'].typ
	rvar_type := gen.idents['${gen.current_fn}.${node.right.str()}'].typ
	if lvar_type == ast.string_type_idx || rvar_type == ast.string_type_idx {
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
				panic('\n\nTranspiler Error:\n"${node.op.str()}" operator not supported for strings.\n')
			}
		}
	} else {
		return '${gen.ast_node(node.left)} ${node.op} ${gen.ast_node(node.right)}'
	}
}