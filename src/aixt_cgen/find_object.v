// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// find_object recursively find object in the global and current scope.
fn (mut gen Gen) find_object(name string, scope ast.Scope) ?ast.ScopeObject {
	if name in scope.objects {
		return scope.objects[name] or { none }
	} else {
		for child in scope.children {
			return gen.find_object(name, child) or { continue }
		}
		return none
	}
}