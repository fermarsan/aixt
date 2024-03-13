// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// call_expr is the code generation function for function calling expressions.
fn (mut gen Gen) call_expr(node ast.CallExpr) string {
	// fn_name := node.name.replace('.', '__')	// remove the parent function name
	mut fn_name := node.name.all_before_last('.')	// only the module name
	fn_name = if node.name.contains('.') {
		'${fn_name.all_after_last('.')}__${node.name.all_after_last('.')}'
	} else {
		fn_name
	}
	// fn_api_path := gen.setup.value('api_functions').as_map()[fn_name] or { '' }	// api path of function
	// if fn_api_path.string() != '' {// self-including of api files
	// 	file_path := '${gen.tr_path}/ports/${gen.setup.value('path').string()}/api/${fn_api_path.string()}.c.v\n'
    // 	// gen.incls += '#include "${file_path}.c"\n'
    // 	if file_path !in gen.api_paths {
	// 		gen.src_paths << file_path
	// 		println(gen.api_paths)
	// 		// parser.free()
	// 		file := parser.parse_file(file_path, ast.new_table(), .skip_comments, gen.pref)

	// 		// file := parser.parse_file(gen.src_paths[gen.src_paths.len-1], gen.table, .skip_comments, gen.pref)
	// 		// gen.out += gen.ast_node(file)
	// 	}
	// }
	mut out := '${fn_name}('
	if node.args.len != 0 {
		for ar in node.args {
			out += '${gen.ast_node(ar)}, '
		}
		out = out#[..-2]
	}
	return out + ')'
}