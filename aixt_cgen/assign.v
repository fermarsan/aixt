// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: assign.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation the assignment statement.
module aixt_cgen

import v.ast

fn (mut gen Gen) assign_stmt(node ast.AssignStmt) string {
	mut out := ''
	mut var_type := ''
	for i in 0 .. node.left.len {
		if node.right[i].type_name() in ['v.ast.IfExpr', 'v.ast.MatchExpr'] {
			gen.cond_assign = true	// conditional assignment flag
		} 

		var_global_name := '${node.left[i].str()}'
		var_name := '${gen.current_fn}.${var_global_name}'
		
		// println(var_name)
		if node.op.str() == ':=' { // declaration-assignment
			gen.idents[var_name] = struct { // add the new symbol
				kind: ast.IdentKind.variable
			}
			gen.idents[var_name].typ = match node.right_types[i] {
				ast.int_literal_type_idx { ast.int_type_idx }
				ast.float_literal_type_idx { ast.f32_type_idx }
				else { node.right_types[i] }	
			}
			var_type = gen.table.type_kind(gen.idents[var_name].typ).str()
			match var_type {
				'array' {
					gen.idents[var_name].len = (node.right[i] as ast.ArrayInit).exprs.len // array len
					gen.idents[var_name].elem_type = (node.right[i] as ast.ArrayInit).elem_type // element type
					var_type = gen.table.type_kind((node.right[i] as ast.ArrayInit).elem_type).str()
					out += '${gen.setup.value(var_type).string()} ' // array's element type
					out += '${gen.ast_node(node.left[i])}[${(node.right[i] as ast.ArrayInit).exprs.len}] = '
					out += '${gen.ast_node(node.right[i])};\n'
				}
				'string' {
					gen.idents[var_name].len = (node.right[i] as ast.StringLiteral).val.len // string len
					gen.idents[var_name].elem_type = ast.rune_type_idx // element type
					if gen.idents[var_name].len != 0 {	// Constant strings
						if gen.setup.value('fixed_size_strings').bool() {
							gen.idents[var_name].kind = ast.IdentKind.constant
						}
						out += 'char ${gen.ast_node(node.left[i])}[] = '
						out += if node.right[i].type_name() == 'v.ast.CastExpr' {
							'${gen.ast_node((node.right[i] as ast.CastExpr).expr)};\n'
						} else { 
							'${gen.ast_node(node.right[i])};\n'
						}
					} else {	// Variable strings
						len := gen.setup.value('string_default_len').int()
						gen.idents[var_name].len = len
						out += 'char ${gen.ast_node(node.left[i])}[${len}];\n'
					}
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
			match node.left[i] {
				ast.Ident {	// if it is a simple variable
					// println(gen.idents)
					if var_name in gen.idents || var_global_name in gen.idents {	// if previously defined
						var_type = if var_name in gen.idents {
							gen.table.type_kind(gen.idents[var_name].typ).str()
						} else if var_global_name in gen.idents {
							gen.table.type_kind(gen.idents[var_global_name].typ).str()
						} else {
							panic('\n\nTranspiler Error:\nUndefined variable "${node.left[i]}".\n')
						}
						match var_type {
							'array' {
								if gen.setup.value('fixed_size_arrays').bool() {
									panic('\n\nTranspiler Error:\nFor now dynamic-size arrays are not allowed.\n')
								}
							}
							'string' {
								// if gen.setup.value('fixed_size_strings').bool() {
								// 	panic('\n\nTranspiler Error:\nFor now dynamic-size strings are not allowed.\n')
								// }
								if gen.idents[var_name].kind == ast.IdentKind.variable {
									match node.op.str() {
										'=' {
											gen.add_include('string.h')
											out += 'strcpy(${gen.ast_node(node.left[i])}, ${gen.ast_node(node.right[i])});\n'
										} 
										'+=' {
											gen.add_include('string.h')
											out += 'strcat(${gen.ast_node(node.left[i])}, ${gen.ast_node(node.right[i])});\n'
										}	
										else {
											panic('\n\nTranspiler Error:\n"${node.op.str()}" operator not supported for strings.\n')
										}
									}
								} else {
									panic('\n\nTranspiler Error:\n"${var_global_name}" is a constant string.\n')
								}
							}
							else {
								out += '${gen.ast_node(node.left[i])} ${node.op} ${gen.ast_node(node.right[i])};\n'
							}
						} 
					} else {
						panic('\n\nTranspiler Error:\nUndefined variable "${node.left[i]}".\n')
					}
				} 
				else {
					out += '${gen.ast_node(node.left[i])} ${node.op} ${gen.ast_node(node.right[i])};\n'
				}
			}
		}
	} 
	return out
}