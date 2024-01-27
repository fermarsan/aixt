// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: branch_stmt.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for branch statements.
module aixt_cgen

import v.ast

fn (mut gen Gen) branch_stmt(node ast.BranchStmt) string {
	return '${node.str()};\n'
}