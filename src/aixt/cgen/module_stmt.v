// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// module_stmt is the code generation function for modules definition.
fn (mut gen Gen) module_stmt(node ast.Module) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	return []	// ['// ${node.name} module']
}