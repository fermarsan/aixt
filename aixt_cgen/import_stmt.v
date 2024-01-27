// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: import_stmt.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for import statements.
module aixt_cgen

import v.ast

fn (mut gen Gen) import_stmt(node ast.Import) string {
	// println('${gen.setup.value('port').string()}')
	api_path := '${gen.transpiler_path}/ports/${gen.setup.value('path').string()}/api'
	if node.syms.len == 0 {
		gen.includes += '#include "${api_path}/${node.mod}.c"\n'
	} else {
		for s in node.syms {
			gen.includes += '#include "${api_path}/${node.mod}/${s.name}.c"\n'
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