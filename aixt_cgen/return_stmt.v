// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: return_stmt.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for return statements.
module aixt_cgen

import v.ast

fn (mut gen Gen) return_stmt(node ast.Return) string {
	// Be Careful....... multiple values return
	return 'return ${gen.ast_node(node.exprs[0])};\n'
}