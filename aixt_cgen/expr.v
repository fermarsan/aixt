// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: expr.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for expressions.
module aixt_cgen

import v.ast

fn (mut gen Gen) if_expr(node ast.IfExpr) string { // basic shape of an "if" expression
	mut out := 'if(${gen.ast_node(node.branches[0].cond)}) {\n${gen.ast_node(node.branches[0])}}\n'
	for i, br in node.branches {
		if i >= 1 {
			out += 'else '
			if br.cond.type_name().str() == 'unknown v.ast.Expr' {	//only 'else'
				out += '{\n${gen.ast_node(br)}}\n'
			} else {
				out += 'if(${gen.ast_node(br.cond)}) {\n${gen.ast_node(br)}}\n'	//'else if'
			}
		} 
	}
	return out
}

fn (mut gen Gen) call_expr(node ast.CallExpr) string {
	mut out := '${node.name.after('.')}('
	if node.args.len != 0 {
		for ar in node.args {
			out += '${gen.ast_node(ar)}, '
		}
		out = out#[..-2]
	}
	return out + ')'
}

fn (mut gen Gen) par_expr(node ast.ParExpr) string {
	return '(${gen.ast_node(node.expr)})'
}

fn (mut gen Gen) infix_expr(node ast.InfixExpr) string {
	return '${gen.ast_node(node.left)} ${node.op} ${gen.ast_node(node.right)}'
}

fn (mut gen Gen) prefix_expr(node ast.PrefixExpr) string {
	return '${node.op}${gen.ast_node(node.right)}'
}

fn (mut gen Gen) postfix_expr(node ast.PostfixExpr) string {
	return '${gen.ast_node(node.expr)}${node.op}'
}

fn (mut gen Gen) index_expr(node ast.IndexExpr) string {
	// Be careful, multiple indexing missing
	return '${gen.ast_node(node.left)}[${gen.ast_node(node.index)}]'
}

fn (mut gen Gen) cast_expr(node ast.CastExpr) string {
	var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())
	return '(${var_type.string()})(${gen.ast_node(node.expr)})'
}

fn (mut gen Gen) array_init(node ast.ArrayInit) string {
	mut out := '{'
	for ex in node.exprs {
		out += '${gen.ast_node(ex)}, '
	}
	out = out#[..-2]
	return out + '}'
}

fn (mut gen Gen) ident(node ast.Ident) string {
	return node.name
}

fn (mut gen Gen) string_literal(node ast.StringLiteral) string {
	return '"${node.val}"'
}

fn (mut gen Gen) char_literal(node ast.CharLiteral) string {
	return "'${node.val}'"
}

fn (mut gen Gen) float_literal(node ast.FloatLiteral) string {
	return node.val
}

fn (mut gen Gen) integer_literal(node ast.IntegerLiteral) string {
	return if node.str().contains('0o') {	// if it is an octal literal
		node.val.int().str() 				// turn it into decimal
	} else {
		node.val
	}
}

fn (mut gen Gen) bool_literal(node ast.BoolLiteral) string {
	return node.val.str()
}
