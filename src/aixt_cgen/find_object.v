// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// find_object recursively find object in the global and current scope.
fn (mut gen Gen) find_object(name string) ?ast.ScopeObject {
	if name in gen.table.global_scope.objects {
		return gen.table.global_scope.objects[name] or { none }
	} else {
		for child in gen.files[gen.file_count].scope.children {
			if name in child.objects {
				return child.objects[name] or { none }
			}
		}
		return none
	}

	// mut all_objects := gen.table.global_scope.objects


	// gen.sym_table_print()
	// mut object := gen.files[gen.file_count].scope.find(name) or { none }
	// if object == none {
	// 	for child in gen.files[gen.file_count].scope.children {
	// 		object = child.find(name) or { none }
	// 		if object != none {
	// 			break
	// 		}
	// 	}
	// }
	// return object
}