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
	mut c_line := ''

	mut strs := node.vals.clone()	//reverse()
	mut exprs := node.exprs.clone()	//reverse()

	// println('............. ${gen.setup.value('backend').str()} .............')	
	len := gen.setup.value('string_default_len').int()
	if gen.setup.value('backend').string() != 'nxc' {
		gen.add_include('stdio.h')
		gen.add_definition('char __temp_str[${len}];')
	} else {
		gen.add_definition('string __temp_str = "${' '.repeat(len)}";')
	}

	mut placeholders := []string{}

	for ex in exprs {
		placeholders << match ex {
			ast.Ident { 
				match gen.find_type(ex) {
					.i8		{ '%d' }	//hh' }
					.i16	{ '%d' }	//h' }
					.i32	{ '%d' }
					.int	{ '%d' }
					.i64	{ '%l' }
					.isize	{ '%d' }
					.u8		{ '%u' }	//hhu' }
					.u16	{ '%u' }	//hu' }
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
	for i in 0 .. exprs.len {
		casting := match placeholders[i] {
			'%d'  	{ '(int)' }
			'%u'  	{ '(unsigned int)' }
			'%l'  	{ '(long int)' }
			'%lu' 	{ '(unsigned long int)' }
			'%f'  	{ '(float)' }
			'%lf' 	{ '(double)' }
			else	{ '' }
		}
		c_line += '${casting}${exprs[i].str()}, '
	}
	c_line = c_line#[..-2] + ');'
	gen.to_insert_lines << c_line
	c_line = '___TO_INSERT_${gen.to_insert_lines.len - 1}___'
	
	return [c_line + '__temp_str']
}