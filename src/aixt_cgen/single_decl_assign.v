// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// single_decl_assign is the code generation function for single declaration-assignment statements.
// This works for:
// - declaration-assignments `:=`
fn (mut gen Gen) single_decl_assign(left ast.Expr, left_type ast.Type, right ast.Expr) string {
	mut c_line := ''
	var_kind := gen.table.type_kind(left_type).str()
	match var_kind {
		'array' {
			var_type := gen.table.type_kind((right as ast.ArrayInit).elem_type).str()
			c_line += '${gen.setup.value(var_type).string()} ' // array's element type
			c_line += '${gen.ast_node(left).join('')}['
			array_len := (right as ast.ArrayInit).exprs.len
			if  array_len != 0 {
				c_line += '${array_len}] = ${gen.ast_node(right).join('')};'
			} else if gen.setup.value('fixed_size_arrays').bool() {
				c_line += '${gen.setup.value('array_default_len').int()}];'	// port with fixed-size arrays
			} else {
				c_line += '];'	// port with dynamic-size arrays
			}
		}
		'string' {
			len := gen.setup.value('string_default_len').int()
			out << 'char ${gen.ast_node(left).join('')}[${len}] = "";'
			gen.add_include('string.h')
			c_line +='strcpy(${gen.ast_node(left).join('')}, ${gen.ast_node(right).join('')});'
		}
		'enum' {
			c_line += 'enum ${(right as ast.EnumVal).enum_name.replace('.', '__')} '
			c_line += '${gen.ast_node(left).join('')} = '
			c_line += '${gen.ast_node(right).join('')};'
		}
		else {
			c_line += '${gen.setup.value(var_kind).string()} ${gen.ast_node(left).join('')} = '
			c_line += if right.type_name() == 'v.ast.CastExpr' {
				'${gen.ast_node((right as ast.CastExpr).expr).join('')};'
			} else {
				'${gen.ast_node(right).join('')};'
			}
		}
	}
	return c_line
}