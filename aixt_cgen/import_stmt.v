// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import os
import v.ast

// import_stmt is the code generation function for import statements.
fn (mut gen Gen) import_stmt(node ast.Import) string {
	// println('${gen.setup.value('port').string()}')
	if node.syms.len == 0 {
		paths := os.ls('${node.mod.replace('.', '/')}') or { [] }
		println(paths)
		for path in paths {
			if path.ends_with('.v') { // || path.ends_with('.aixt') {
				gen.parse_cgen_file(os.abs_path('${node.mod.replace('.', '/')}/${path}'))
			}
		}
	} else {
		for s in node.syms {
			gen.parse_cgen_file(os.abs_path('${node.mod.replace('.', '/')}/${s.name}.v'))
		}
	}

	return ''
}