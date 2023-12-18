// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: expr.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for expressions.
module aixt_cgen

import v.ast

fn (mut gen Gen) call_expr(node ast.CallExpr) string {
	fn_name := node.name.after('.')	// remove the parent function name
	fn_api_path := gen.setup.value('api_functions').as_map()[fn_name] or { '' }	// api path of function
	if fn_api_path.string() != '' && !gen.includes.contains(fn_api_path.string()){	// self-including of api files
		api_path := '${gen.base_path}/ports/${gen.setup.value('path').string()}/api'
    	gen.includes += '#include "${api_path}/${fn_api_path.string()}.c"\n'
	}
	mut out := '${fn_name}('
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
	lvar_type := gen.idents['${gen.current_fn}.${node.left.str()}'].typ
	rvar_type := gen.idents['${gen.current_fn}.${node.right.str()}'].typ
	if lvar_type == ast.string_type_idx || rvar_type == ast.string_type_idx {
		match node.op.str() {
			'==' {
				if !gen.includes.contains('strings/comp.c') {
					api_path := '${gen.base_path}/ports/${gen.setup.value('path').string()}/api'
					gen.includes += '#include "${api_path}/strings/comp.c"\n'
				}
				return '__string_comp(${gen.ast_node(node.left)}, ${gen.ast_node(node.right)})'
			} 
			'+' {
				if !gen.includes.contains('strings/add.c') {
					api_path := '${gen.base_path}/ports/${gen.setup.value('path').string()}/api'
					gen.includes += '#include "${api_path}/strings/add.c"\n'
				}
				return '__string_add(${gen.ast_node(node.left)}, ${gen.ast_node(node.right)})'
			}	
			else {
				panic('\n\nTranspiler Error:\n"${node.op.str()}" operator not supported for strings.\n')
			}
		}
	} else {
		return '${gen.ast_node(node.left)} ${node.op} ${gen.ast_node(node.right)}'
	}
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
	var_type := gen.table.type_kind(node.typ).str()
	return '(${gen.setup.value(var_type).string()})(${gen.ast_node(node.expr)})'
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
	// println('${node.name}-${node.scope.parent}')
	return node.name.after('.')
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
	return if node.str().contains('0o') { // if it is an octal literal
		node.val.int().str() // turn it into decimal
	} else {
		node.val
	}
}

fn (mut gen Gen) bool_literal(node ast.BoolLiteral) string {
	return node.val.str()
}
