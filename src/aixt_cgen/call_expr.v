// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// call_expr is the code generation function for function calling expressions.
fn (mut gen Gen) call_expr(node ast.CallExpr) []string {
	// println("+++++++++++++++ ${node.name} +++++++++++++++")
	// println("+++++++++++++++\n${node.language}\n+++++++++++++++")
	// println("+++++++++++++++ ${node.name} +++++++++++++++")
	// println("+++++++++++++++\n${node.return_type}\n+++++++++++++++")
	// println("+++++++++++++++\n${node.mod.all_after_last('.')}\n+++++++++++++++")
	// println("+++++++++++++++ ${node.mod} +++++++++++++++")
	fn_name := match node.language {
		.c {
			node.name.replace('C.', '')
		}
		else {
			if node.left.str().starts_with('C.') {	// for C++ methods
				'${node.left.str().replace('C.', '')}.${node.name}'
			} else if node.name.contains('.') {
				node.name.replace('.', '__')
			} else if node.mod.all_after_last('.') == 'main' && gen.setup.backend == 'nxc' {
				'${node.name.all_after_last('.')}'
			} else {
				'${node.mod.all_after_last('.')}__${node.name.all_after_last('.')}'
			}
		}
	}
	mut c_line := '${fn_name}('
	if node.args.len != 0 {
		for ar in node.args {
			c_line += '${gen.ast_node(ar).join('')}, '
		}
		c_line = c_line#[..-2]
	}
	return [c_line + ')']
}