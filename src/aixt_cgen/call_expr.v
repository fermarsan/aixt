// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// call_expr is the code generation function for function calling expressions.
fn (mut gen Gen) call_expr(node ast.CallExpr) []string {
	// println("+++++++++++++++\n${node.name}\n+++++++++++++++")
	// println("+++++++++++++++\n${node.mod}\n+++++++++++++++")
	// println("+++++++++++++++\n${node.mod.all_after_last('.')}\n+++++++++++++++")
	fn_name := if node.name.contains('.') {
		node.name.replace('.', '__')
	} else if node.mod.all_after_last('.') == 'main' && gen.setup.value('backend').string() == 'nxc' {
		'${node.name.all_after_last('.')}'
	} else {
		'${node.mod.all_after_last('.')}__${node.name.all_after_last('.')}'
	}
	mut c_line := '${fn_name}('
	if node.args.len != 0 {
		for ar in node.args {
			c_line += '${gen.ast_node(ar).join('')}, '
		}
	}
	return [c_line#[..-2] + ');']
}