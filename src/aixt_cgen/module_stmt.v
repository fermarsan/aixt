// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// module_stmt is the code generation function for modules definition.
fn (mut gen Gen) module_stmt(node ast.Module) []string {
	return ['// ${node.name} module']
}