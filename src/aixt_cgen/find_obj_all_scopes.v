// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// find_obj_all_scopes recursively finds an object in all the scopes.
fn (mut gen Gen) find_obj_all_scopes(name string) ?ast.ScopeObject {
	// find in the global scope
	mut obj := gen.find_object(name, gen.table.global_scope) or {
		ast.Var { name: '__not_found__' } 
	}
	// find in the rest of file scopes
	if obj.name == '__not_found__' {
		for file in gen.files {
			obj = gen.find_object(name, file.scope) or { continue } 
			break
		}
	}
	return if obj.name != '__not_found__' { obj } else { none }
}