// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// expr is the code generation function for expressions.
fn (mut gen Gen) expr(node ast.Expr) string {
	println('${node.type_name().after('v.ast.')}:\t\t${node}')
	match node {
		ast.IfExpr { // basic shape of an "if" expression
			return gen.if_expr(node)
		}
		ast.MatchExpr {
			return gen.match_expr(node)
		}
		ast.CallExpr {
			return gen.call_expr(node)
		}
		ast.ParExpr {
			return gen.par_expr(node)
		}
		ast.InfixExpr {
			return gen.infix_expr(node)
		}
		ast.PrefixExpr {
			return gen.prefix_expr(node)
		}
		ast.PostfixExpr {
			return gen.postfix_expr(node)
		}
		ast.IndexExpr {
			return gen.index_expr(node)
		}
		ast.CastExpr {
			return gen.cast_expr(node)
		}
		ast.ArrayInit {
			return gen.array_init(node)
		}
		ast.Ident {
			// println('---1---')
			return gen.ident(node)
		}
		ast.StringLiteral {
			return gen.string_literal(node)
		}
		ast.StringInterLiteral {
			return gen.string_inter_literal(node)
		}
		ast.CharLiteral {
			return gen.char_literal(node)
		}
		ast.FloatLiteral {
			return gen.float_literal(node)
		}
		ast.IntegerLiteral {
			return gen.integer_literal(node)
		}
		ast.BoolLiteral {
			return gen.bool_literal(node)
		}
		ast.EnumVal {
			return gen.enum_val(node)
		}
		ast.EmptyExpr {
			return ''
		}
		else { panic('\n\n***** Transpiler error *****:\nUndefined expression.\n') }
	}		
}