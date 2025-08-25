// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast

// call_expr is the code generation function for function calling expressions.
fn (mut gen Gen) call_expr(node ast.CallExpr) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
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
			} else if node.is_method {
				_, mut var_type := gen.get_str_c_type(node.left_type, false)
				var_type = var_type.replace('.', '__')
				'${var_type}_${node.name}'
			} else {
				'${node.mod.all_after_last('.')}__${node.name.all_after_last('.')}'
			}
		}
	}

	mut c_line := '${fn_name}('
	if node.is_method {
		c_line += '&${node.left}, '
	}
	if node.args.len != 0 {
		for ar in node.args {
			c_line += '${gen.ast_node(ar).join('')}, '
		}
	}
	if c_line#[-2..] == ', ' {
		c_line = c_line#[..-2]
	}
	return [c_line + ')']
}