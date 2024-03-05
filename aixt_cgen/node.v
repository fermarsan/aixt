// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT

module aixt_cgen

import v.ast

// ast_node is the Code generation function for AST nodes.
fn (mut gen Gen) ast_node(node ast.Node) string {
	if node.type_name() == 'v.ast.File' {
		println('')
	}
	print('${node.type_name().after('v.ast.')} -> ')
	match node {
		ast.File {
			return gen.ast_file(node)
		}
		ast.Stmt {
			return gen.stmt(node)
		}
		ast.Expr {
			return gen.expr(node)
		}
		ast.ConstField {
			return gen.const_field(node)
		}
		ast.GlobalField {
			return gen.global_field(node)
		}
		ast.EnumField {
			return gen.enum_field(node)
		}
		ast.IfBranch { // statement block of "if" and "else" expressions
			return gen.if_branch(node)
		}
		ast.CallArg {
			return gen.call_arg(node)
		}
		ast.Param {
			return gen.param(node)
		}
		else {
			return ''
		} //'Error: Not defined node.\n' }
	}
}