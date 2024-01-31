// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// import_stmt is the code generation function for import statements.
fn (mut gen Gen) import_stmt(node ast.Import) string {
	// println('${gen.setup.value('port').string()}')
	api_path := '${gen.tr_path}/ports/${gen.setup.value('path').string()}/api'
	if node.syms.len == 0 {
		gen.incls += '#include "${api_path}/${node.mod}.c"\n'
	} else {
		for s in node.syms {
			gen.incls += '#include "${api_path}/${node.mod}/${s.name}.c"\n'
		}
	}

	// for f in node.fields {
	// 	out += '${gen.ast_node(f)}'
	// }
	// println('------------${node.mod}------------')
	// println(node.alias)
	// println(node.syms)	
	return ''
}