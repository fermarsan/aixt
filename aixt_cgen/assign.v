// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: assign.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation the assignment statement.
module aixt_cgen

import v.ast
import v.token

fn (mut gen Gen) assign_stmt(node ast.AssignStmt) string {
	mut out := ''
	// mut left := ''
	// mut right := ''
	for i in 0 .. node.left.len {
		gen.idents[node.left[i].str()] = struct { // add the new symbol
			kind: ast.IdentKind.variable
			// typ: node.right_types[i]
		}
		gen.idents[node.left[i].str()].typ = match node.right_types[i] {
			ast.int_literal_type_idx { ast.int_type_idx }
			ast.float_literal_type_idx { ast.f32_type_idx }
			else { node.right_types[i] }	
		}
		mut var_type := gen.table.type_kind(gen.idents[node.left[i].str()].typ).str()
		if node.op == token.Kind.decl_assign { // declaration
			match var_type {
				'array' {
					if gen.setup.value('fixed_size_arrays').bool() {
						gen.idents[node.left[i].str()].len = (node.right[i] as ast.ArrayInit).exprs.len // array len
						gen.idents[node.left[i].str()].elem_type = (node.right[i] as ast.ArrayInit).elem_type // element type
						var_type = gen.table.type_kind((node.right[i] as ast.ArrayInit).elem_type).str()
						out += '${gen.setup.value(var_type).string()} ' // array's element type
						out += '${gen.ast_node(node.left[i])}[${(node.right[i] as ast.ArrayInit).exprs.len}] = '
						out += '${gen.ast_node(node.right[i])};\n'
					} else {
						out += 'Dynamic-size arrays are not allowed for now'
					}
				}
				'string' {
					// if gen.setup.value('fixed_size_strings').bool() {
					gen.idents[node.left[i].str()].len = (node.right[i] as ast.StringLiteral).val.len // string len
					gen.idents[node.left[i].str()].elem_type = ast.rune_type_idx // element type
					out += 'char ${gen.ast_node(node.left[i])}[] = '
					out += if node.right[i].type_name() == 'v.ast.CastExpr' {
						'${gen.ast_node((node.right[i] as ast.CastExpr).expr)};\n'
					} else { 
						'${gen.ast_node(node.right[i])};\n'
					}
					//  } else {
					// 	out += "Dynamic-size strings are not allowed for now"
					//  }
				}
				else {
					out += '${gen.setup.value(var_type).string()} ${gen.ast_node(node.left[i])} = '
					out += if node.right[i].type_name() == 'v.ast.CastExpr' {
						'${gen.ast_node((node.right[i] as ast.CastExpr).expr)};\n'
					} else {
						'${gen.ast_node(node.right[i])};\n'
					}
				}
			}
		} else { // for the rest of assignments
			out += '${gen.ast_node(node.left[i])} ${node.op} ${gen.ast_node(node.right[i])};\n'
		}
	} 
	return out
}
