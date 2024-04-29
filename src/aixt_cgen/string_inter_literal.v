// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// string_inter_literal is the code generation function for string literals with interpolation.
// ```v
// str := 'Hello ${var_name}...'
// ```
fn (mut gen Gen) string_inter_literal(node ast.StringInterLiteral) []string {
	mut out := []string{}
	mut c_line := ''

	mut strs := node.vals.clone()	//reverse()
	mut exprs := node.exprs.clone()	//reverse()

	gen.add_include('stdio.h')
	len := gen.setup.value('string_default_len').int()
	gen.add_definition('char __temp_str[${len}];')

	mut placeholders := []string{}

	for ex in exprs {
		placeholders << match ex {
			ast.Ident { 
				match gen.find_type(ex) {
					.i8		{ '%hh' }
					.i16	{ '%h' }
					.i32	{ '%d' }
					.int	{ '%d' }
					.i64	{ '%l' }
					.isize	{ '%d' }
					.u8		{ '%hhu' }
					.u16	{ '%hu' }
					.u32	{ '%u' }
					.u64	{ '%lu' }
					.usize	{ '%u' }
					.f32	{ '%f' }
					.f64	{ '%lf' }
					.char, .rune 	{ '%c' }
					.string 		{ '%s' }
					else	{ '' }
				}
			}
			ast.CallExpr {
				'%d'
				// '${(cur_expr as ast.CallExpr).name}, '
			}
			ast.InfixExpr {
				'%d'
				// '${(cur_expr as ast.InfixExpr).left}, '
			}
			else {
				'none, '
			}
		}
	}

	c_line += 'sprintf(__temp_str, "${strs[0]}'
	for i in 1 .. strs.len {
		c_line += "${placeholders[i-1]}${strs[i]}"
	}
	c_line += '", '
	for ex in exprs {
		c_line += '${ex.str()}, '
	}
	c_line = c_line#[..-2] + ');'
	out << c_line + ' //___MOVE_BACK_1___'	
	out << '__temp_str'
	return out

	// mut out := 'strcat(__temp_str, strcat(${strs.pop()}, '// first sub-string
	// for exprs.len > 0 {
	// 	out += 'strcat('
	// 	cur_expr := exprs.pop()
	// 	match cur_expr {
	// 		ast.Ident { 
	// 			match gen.find_type(cur_expr) {
	// 				.i8, .i16, .i32, .int, .i64, .isize, .u8, .u16, .u32, .u64, .usize {
	// 					gen.add_include('stdlib.h')
	// 					out += 'itoa(${cur_expr as ast.Ident).name}, __temp_str, 10), '
	// 				}
	// 				.f32, .f64 {
	// 					gen.add_include('stdlib.h')
	// 					out += 'ftoa(${cur_expr as ast.Ident).name}, __temp_str, 10), '
	// 				}
	// 				.string {
	// 					out += '${(cur_expr as ast.Ident).name}, '
	// 				}
	// 			}
	// 			'(${})${(cur_expr as ast.Ident).name}, '
	// 		}
	// 		ast.CallExpr {
	// 			'${(cur_expr as ast.CallExpr).name}, '
	// 		}
	// 		ast.InfixExpr {
	// 			'${(cur_expr as ast.InfixExpr).left}, '
	// 		}
	// 		else {
	// 			'none, '
	// 		}
	// 	}
	// 	out += 'strcat(${strs.pop()}, '
	// }
	
	// return out //sprintf(${gen.ast_node(node.left[i])}, ${gen.ast_node(node.right[i])});\n'
}