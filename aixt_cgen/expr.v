// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: expr.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for expressions.
module aixt_cgen

import v.ast

fn (mut gen Gen) if_expr(node ast.IfExpr) { // basic shape of an "if" expression
	mut out := 'if(__v.ast.Expr__){\n__v.ast.Stmt__}\n'
	out += if node.has_else { 'else{\n__v.ast.Stmt__}\n' } else { '' }
	gen.out = gen.out.replace_once('__v.ast.IfExpr__', out)
}

fn (mut gen Gen) call_expr(node ast.CallExpr) {
	mut call_expr := '${node.name.after('.')}('
	call_expr += if node.args.len != 0 { 
		'__v.ast.CallArg__, '.repeat(node.args.len)#[..-2] + ')' 
	} else {
		')'
	}
	gen.out = gen.out.replace_once('__v.ast.CallExpr__', call_expr)
}

fn (mut gen Gen) par_expr(node ast.ParExpr) {
	gen.out = gen.out.replace_once('__v.ast.ParExpr__', '(__${node.expr.type_name()}__)')
	// println(node.expr)
}

fn (mut gen Gen) infix_expr(node ast.InfixExpr) {
	gen.out = gen.out.replace_once('__v.ast.InfixExpr__', 
								   '__${node.left.type_name()}__ ${node.op} __${node.right.type_name()}__')
	gen.ast_node(node.left)
	gen.ast_node(node.right)
}

fn (mut gen Gen) prefix_expr(node ast.PrefixExpr) {
	gen.out = gen.out.replace_once('__v.ast.PrefixExpr__', '${node.op}__${node.right.type_name()}__')
	gen.ast_node(node.right)
}

fn (mut gen Gen) postfix_expr(node ast.PostfixExpr) {
	gen.out = gen.out.replace_once('__v.ast.PostfixExpr__', '__${node.expr.type_name()}__${node.op}')
}

fn (mut gen Gen) cast_expr(node ast.CastExpr) {
	var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())
	gen.out = gen.out.replace_once('__v.ast.CastExpr__', '(${var_type.string()})(${node.expr})')
}

fn (mut gen Gen) ident(node ast.Ident) {
	gen.out = gen.out.replace_once('__v.ast.Ident__', node.name)
}

fn (mut gen Gen) string_literal(node ast.StringLiteral) {
	gen.out = gen.out.replace_once('__v.ast.StringLiteral__', '"${node.val}"')
}

fn (mut gen Gen) char_literal(node ast.CharLiteral) {
	gen.out = gen.out.replace_once('__v.ast.CharLiteral__', "'${node.val}'")
}

fn (mut gen Gen) float_literal(node ast.FloatLiteral) {
	gen.out = gen.out.replace_once('__v.ast.FloatLiteral__', node.val)
}

fn (mut gen Gen) integer_literal(node ast.IntegerLiteral) {
	out := if node.str().contains('0o') {	// if it is an octal literal
		node.val.int().str() 				// turn it into decimal
	} else {
		node.val
	}
	gen.out = gen.out.replace_once('__v.ast.IntegerLiteral__', out)
}

fn (mut gen Gen) bool_literal(node ast.BoolLiteral) {
	gen.out = gen.out.replace_once('__v.ast.BoolLiteral__', node.val.str())
}
