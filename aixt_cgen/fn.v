
// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: fn.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for the function declaration statement.
module aixt_cgen

import v.ast

fn (mut gen Gen) fn_decl(node ast.FnDecl) string {
	mut out := ''
	if node.is_main {
		gen.current_fn = 'main'
		out += if gen.setup.value('backend').string() == 'nxc' { 'task ' } else { '' }
		out += '${gen.setup.value('main_ret_type').string()} '
		out += 'main(${gen.setup.value('main_params').string()}) {\n'
		// println('fn stmts:\t${node.stmts}')
		for st in node.stmts {
			out += gen.ast_node(st)
			// println('fn stmt:\t${st}')
		}
		out += if gen.setup.value('main_ret_type').string() == 'int' { 'return 0;\n}' } else { '}' }
		out = if out[0] == ` ` { out[1..] } else { out }
	} else {
		gen.current_fn = node.name
		for a in node.attrs {
			out += '${a.name} '
		}
		out += '${gen.setup.value(ast.new_table().type_symbols[node.return_type].str()).string()} ' // return type
		out += '${node.name.after('.')}('
		if node.params.len != 0 {
			for pr in node.params {
				out += '${gen.ast_node(pr)}, '
				println(pr.name)
			}
			out = out#[..-2] + ') {\n'
		} else {
			') {\n'
		}
		for st in node.stmts {
			out += gen.ast_node(st)
		}
		out += '}\n'
		out = if out[0] == ` ` { out[1..] } else { out }
	}
	return out
}