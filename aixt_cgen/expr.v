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
	// for i, br in node.branches {
	// 	if i >= 1 {
	// 		if node.branches.len == 2 {
	// 			out += 'else{\n${gen.ast_node(node.branches[1])}}\n'
	// 		}
	// 		else {
	// 			out += 'else if(${gen.ast_node(node.branches[1].cond)}) {\n${gen.ast_node(node.branches[1])}}\n'
	// 		}
	// 	} 
	// 	match i {
	// 		0 {
	// 			out += '
	// 		}	
	// 		node.branches.len {		// final 'else'

	// 		}
	// 		else {

	// 		}
	// 	}
	// 	'{\n${gen.ast_node(node.branches[0])}}\n'
	// out += if node.has_else {  } else { '' }
	// gen.out = gen.out.replace_once('__v.ast.IfExpr__', out)
	// for br in node.branches {
	// 	gen.ast_node(br)
	// }
	return out
}

fn (mut gen Gen) call_expr(node ast.CallExpr) string {
	mut out := ''
	mut call_expr := '${node.name.after('.')}('
	call_expr += if node.args.len != 0 { 
		'__v.ast.CallArg__, '.repeat(node.args.len)#[..-2] + ')' 
	} else {
		')'
	}
	gen.out = gen.out.replace_once('__v.ast.CallExpr__', call_expr)
	return out
}

fn (mut gen Gen) par_expr(node ast.ParExpr) string {
	mut out := ''
	gen.out = gen.out.replace_once('__v.ast.ParExpr__', '(__${node.expr.type_name()}__)')
	// println(node.expr)
	return out
	
}

fn (mut gen Gen) infix_expr(node ast.InfixExpr) string {
	mut out := ''
	gen.out = gen.out.replace_once('__v.ast.InfixExpr__', 
								   '__${node.left.type_name()}__ ${node.op} __${node.right.type_name()}__')
	gen.ast_node(node.left)
	gen.ast_node(node.right)
	return out
}

fn (mut gen Gen) prefix_expr(node ast.PrefixExpr) string {
	mut out := ''
	gen.out = gen.out.replace_once('__v.ast.PrefixExpr__', '${node.op}__${node.right.type_name()}__')
	gen.ast_node(node.right)
	return out
}

fn (mut gen Gen) postfix_expr(node ast.PostfixExpr) string {
	mut out := ''
	gen.out = gen.out.replace_once('__v.ast.PostfixExpr__', '__${node.expr.type_name()}__${node.op}')
	gen.ast_node(node.expr)
	return out
}

fn (mut gen Gen) cast_expr(node ast.CastExpr) string {
	mut out := ''
	var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())
	gen.out = gen.out.replace_once('__v.ast.CastExpr__', '(${var_type.string()})(__${node.expr.type_name()}__)')
	gen.ast_node(node.expr)
	return out
}

fn (mut gen Gen) ident(node ast.Ident) string {
	return node.name
}

fn (mut gen Gen) string_literal(node ast.StringLiteral) string {
	mut out := ''
	gen.out = gen.out.replace_once('__v.ast.StringLiteral__', '"${node.val}"')
	return out
}

fn (mut gen Gen) char_literal(node ast.CharLiteral) string {
	mut out := ''
	gen.out = gen.out.replace_once('__v.ast.CharLiteral__', "'${node.val}'")
	return out
}

fn (mut gen Gen) float_literal(node ast.FloatLiteral) string {
	mut out := ''
	gen.out = gen.out.replace_once('__v.ast.FloatLiteral__', node.val)
	return out
}

fn (mut gen Gen) integer_literal(node ast.IntegerLiteral) string {
	out := if node.str().contains('0o') {	// if it is an octal literal
		node.val.int().str() 				// turn it into decimal
	} else {
		node.val
	}
	println(out)
	return out
}

fn (mut gen Gen) bool_literal(node ast.BoolLiteral) string {
	mut out := ''
	gen.out = gen.out.replace_once('__v.ast.BoolLiteral__', node.val.str())
	return out
}
