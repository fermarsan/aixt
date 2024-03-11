// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// return_stmt is the code generation function for return statements.
fn (mut gen Gen) return_stmt(node ast.Return) string {
	// Be Careful....... multiple values return
	return 'return ${gen.ast_node(node.exprs[0])};\n'
}