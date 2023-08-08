// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: node.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for AST nodes.
module aixt_cgen

import v.ast

fn (mut gen Gen) stmt(node ast.Stmt) string {
	println('${node.type_name().after('v.ast.')}:\t\t${node}')
	match node {
		ast.FnDecl {
			return gen.fn_decl(node)
		}
		ast.AssignStmt {
			return gen.assign_stmt(node)
		}
		ast.ExprStmt {
			return gen.expr_stmt(node)
		}
		ast.Return {
			return gen.return_stmt(node)
		}
		ast.BranchStmt {
			return gen.branch_stmt(node)
		}
		ast.ForStmt {
			return gen.for_stmt(node)
		}
		ast.ForCStmt {
			return gen.for_c_stmt(node)
		}
		ast.ForInStmt {
			return gen.for_in_stmt(node)
		}
		else { panic('\n\n***** Transpiler error *****:\nUndefined statement.\n') }
	}
}

fn (mut gen Gen) expr(node ast.Expr) string {
	println('${node.type_name().after('v.ast.')}:\t\t${node}')
	match node {
		ast.IfExpr { // basic shape of an "if" expression
			return gen.if_expr(node)
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
		else { panic('\n\n***** Transpiler error *****:\nUndefined expression.\n') }
	}		
}

fn (mut gen Gen) call_arg(node ast.CallArg) string {	
	return '${gen.ast_node(node.expr)}'
}

fn (mut gen Gen) param(node ast.Param) string {
	var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())		
	return '${var_type.string()} ${node.name}'
}