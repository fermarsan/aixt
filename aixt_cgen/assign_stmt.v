// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// assign_stmt is the code generation function for assignment statements.
// This works for:
// - declaration-assignments `:=`
// - only assignments `:=`
// and
// - cumulative-assignments `+=`, `-=`, etc. 
fn (mut gen Gen) assign_stmt(node ast.AssignStmt) string {
	// println('############# ${node} #############')	
	mut out := ''
	mut var_kind := ''
	for i in 0 .. node.left.len {
		var_kind = if node.left_types.len != 0 { gen.table.type_kind(node.left_types[i]).str() } else { '' }

		if node.op.str() == ':=' { // declaration-assignment
			match var_kind {
				'array' {
					var_kind = gen.table.type_kind((node.right[i] as ast.ArrayInit).elem_type).str()
					out += '${gen.setup.value(var_kind).string()} ' // array's element type
					out += '${gen.ast_node(node.left[i])}[${(node.right[i] as ast.ArrayInit).exprs.len}] = '
					out += '${gen.ast_node(node.right[i])};\n'
				}
				'string' {
					if (node.right[i] as ast.StringLiteral).val.len != 0 { // Constant strings
						out += 'char ${gen.ast_node(node.left[i])}[] = '
						out += if node.right[i].type_name() == 'v.ast.CastExpr' {
							'${gen.ast_node((node.right[i] as ast.CastExpr).expr)};\n'
						} else { 
							'${gen.ast_node(node.right[i])};\n'
						}
					} else {	// Variable strings
						len := gen.setup.value('string_default_len').int()
						out += 'char ${gen.ast_node(node.left[i])}[${len}];\n'
					}
				}
				'enum' {
					out += 'enum ${(node.right[i] as ast.EnumVal).enum_name.replace('.', '__')} '
					out += '${gen.ast_node(node.left[i])} = '
					out += '${gen.ast_node(node.right[i])};\n'
				}
				else {
					out += '${gen.setup.value(var_kind).string()} ${gen.ast_node(node.left[i])} = '
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
					match var_kind {
						'array' {
							if gen.setup.value('fixed_size_arrays').bool() {
								panic('\n\nTranspiler Error:\nFor now dynamic-size arrays are not allowed.\n')
							}
						}
						'string' {
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
						}
						else {
							out += '${gen.ast_node(node.left[i])} ${node.op} ${gen.ast_node(node.right[i])};\n'
						}
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