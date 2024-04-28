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
fn (mut gen Gen) string_inter_literal(node ast.StringInterLiteral) string {
	mut strs := node.vals.reverse()
	mut exprs := node.exprs.reverse()
	gen.add_include('string.h')
	len := gen.setup.value('string_default_len').int()
	gen.add_definition('char __temp_str[${len}];')
	mut out := 'strcat(__temp_str, strcat(${strs.pop()}, '// first sub-string
	for exprs.len > 0 {
		out += 'strcat('
		cur_expr := exprs.pop()
		out += match cur_expr {
			ast.Ident { 
				'${(cur_expr as ast.Ident).name}, '
			}
			ast.CallExpr {
				'${(cur_expr as ast.CallExpr).name}, '
			}
			ast.InfixExpr {
				'${(cur_expr as ast.InfixExpr).left}, '
			}
			else {
				'none, '
			}
		}
		match cur_expr {
			ast.Ident { 
				
			}
			ast.CallExpr {
				
			}
			ast.InfixExpr {
				println('${(cur_expr as ast.InfixExpr).promoted_type}')
				println(gen.table.type_symbols)
			}
			else {
				
			}
		}
		out += 'strcat(${strs.pop()}, '
	}
	
	return out //sprintf(${gen.ast_node(node.left[i])}, ${gen.ast_node(node.right[i])});\n'
}