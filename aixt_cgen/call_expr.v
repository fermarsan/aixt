// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// call_expr is the code generation function for function calling expressions.
fn (mut gen Gen) call_expr(node ast.CallExpr) string {
	fn_name := node.name.after('.')	// remove the parent function name
	fn_api_path := gen.setup.value('api_functions').as_map()[fn_name] or { '' }	// api path of function
	if fn_api_path.string() != '' && !gen.incls.contains(fn_api_path.string()) {// self-including of api files
		api_path := '${gen.tr_path}/ports/${gen.setup.value('path').string()}/api'
    	// gen.incls += '#include "${api_path}/${fn_api_path.string()}.c"\n'
    	gen.inc_paths << '${api_path}/${fn_api_path.string()}.c.v\n'
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