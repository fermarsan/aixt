// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: node.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for AST nodes.
module aixt_cgen

import v.ast

fn (mut gen Gen) ast_file(node ast.File) string {
    mut out := '// Aixt project ('
    out += if gen.setup.value('backend').string() == 'nxc' { 'NXC ' }  else { 'C ' }
    out += 'generated code)\n// Device = ${gen.setup.value('device').string()}'
	out += '\n// Board = ${gen.setup.value('board').string()}\n\n' 
    for h in gen.setup.value('headers').array() {			// append the header files
        out +=  if h.string() != '' { '#include <${h.string()}>\n' } else { '' }
	}
    out += '\n'
    // out += '#include "api/builtin.h"\n'
    for m in gen.setup.value('macros').array() { 			// append the macros
        out += if m.string() != '' { '#define ${m.string()}\n' } else { '' }
	}
    out += '\n'
    for c in gen.setup.value('configuration').array() {		// append the configuration lines
        out += '${gen.setup.value('config_operator').string()} ${c.string()}\n'    
	}
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	return out
}

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
		else { return '' }//'Error: Not defined statement.\n' }
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
		ast.CastExpr {
			return gen.cast_expr(node)
		}
		ast.Ident {
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
		else { return '' }//'Error: Not defined expression.\n' }
	}		
}

fn (mut gen Gen) const_field(node ast.ConstField) string {
	mut out := ''
	var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())			
	if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
		out += if var_type.string() == 'char []' {
			'const char ${node.name.after('.')}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		} else {
			'const ${var_type.string()} ${node.name.after('.')} = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		}								
	} else {
		out += if var_type.string() == 'char []' {
			'const char ${node.name.after('.')}[] = ${gen.ast_node(node.expr)};\n'
		} else {
			'const ${var_type.string()} ${node.name.after('.')} = ${gen.ast_node(node.expr)};\n'
		}
	}
	return out
}

fn (mut gen Gen) if_branch(node ast.IfBranch) string { // statements block of "if" and "else" expressions
	mut out := ''
	for st in node.stmts {
		out += gen.ast_node(st)
	}
	return out
}

fn (mut gen Gen) call_arg(node ast.CallArg) string {	
	return '${gen.ast_node(node.expr)}'
}

fn (mut gen Gen) param(node ast.Param) string {
	var_type := gen.setup.value(ast.new_table().type_symbols[node.typ].str())		
	return '${var_type.string()} ${node.name}'
}
