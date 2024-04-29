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
fn (mut gen Gen) assign_stmt(node ast.AssignStmt) []string {
	// println('############# ${node} #############')	
	mut out := []string{}
	mut c_line := ''
	mut var_kind := ''
	for i in 0 .. node.left.len {
		var_kind = if node.left_types.len != 0 { gen.table.type_kind(node.left_types[i]).str() } else { '' }
		// println(',,,,,,,,,,,${var_kind},,,,,,,,,,,')

		if node.op.str() == ':=' { // declaration-assignment
			match var_kind {
				'array' {
					var_kind = gen.table.type_kind((node.right[i] as ast.ArrayInit).elem_type).str()
					c_line += '${gen.setup.value(var_kind).string()} ' // array's element type
					c_line += '${gen.ast_node(node.left[i]).join('')}['
					array_len := (node.right[i] as ast.ArrayInit).exprs.len
					if  array_len != 0 {
						c_line += '${array_len}] = ${gen.ast_node(node.right[i]).join('')};'
					} else if gen.setup.value('fixed_size_arrays').bool() {
						c_line += '${gen.setup.value('array_default_len').int()}];'	// port with fixed-size arrays
					} else {
						c_line += '];'	// port with dynamic-size arrays
					}
					out << c_line
				}
				'string' {
					len := gen.setup.value('string_default_len').int()
					out << 'char ${gen.ast_node(node.left[i]).join('')}[${len}] = "";'
					gen.add_include('string.h')
					out << 'strcpy(${gen.ast_node(node.left[i]).join('')}, ${gen.ast_node(node.right[i]).join('')});'
				}
				'enum' {
					c_line += 'enum ${(node.right[i] as ast.EnumVal).enum_name.replace('.', '__')} '
					c_line += '${gen.ast_node(node.left[i]).join('')} = '
					out << c_line + '${gen.ast_node(node.right[i]).join('')};'
				}
				else {
					c_line += '${gen.setup.value(var_kind).string()} ${gen.ast_node(node.left[i]).join('')} = '
					c_line += if node.right[i].type_name() == 'v.ast.CastExpr' {
						'${gen.ast_node((node.right[i] as ast.CastExpr).expr)};'
					} else {
						'${gen.ast_node(node.right[i]).join('')};'
					}
					out << c_line
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
									out << 'strcpy(${gen.ast_node(node.left[i]).join('')}, ${gen.ast_node(node.right[i]).join('')});'
								} 
								'+=' {
									gen.add_include('string.h')
									out << 'strcat(${gen.ast_node(node.left[i]).join('')}, ${gen.ast_node(node.right[i]).join('')});'
								}	
								else {
									panic('\n\nTranspiler Error:\n"${node.op.str()}" operator not supported for strings.\n')
								}
							}
						}
						else {
							out << '${gen.ast_node(node.left[i]).join('')} ${node.op} ${gen.ast_node(node.right[i]).join('')};'
						}
					} 
				} 
				else {
					out << '${gen.ast_node(node.left[i]).join('')} ${node.op} ${gen.ast_node(node.right[i]).join('')};'
				}
			}
		}
	} 
	return out
}