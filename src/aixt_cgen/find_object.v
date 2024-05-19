// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// find_object recursively find object in the global and current scope.
fn (mut gen Gen) find_object(name string, scope ast.Scope) ?ast.ScopeObject {
	// println('"#".repeat(25)\n${}\n"#".repeat(25)')
	// println('${"#".repeat(10)} ${gen.table.global_scope.objects} ${"#".repeat(10)}')
	// println('${"#".repeat(10)} ${gen.files[gen.file_count].scope.children} ${"#".repeat(10)}')
	// mut obj := ast.
	
	if name in scope.objects {
		return scope.objects[name] or { none }
	} else {
		for child in scope.children {
			return gen.find_object(name, child) or { continue }
		}
		return none
	}
	
	
	// if name in gen.table.global_scope.objects {
	// 	return gen.table.global_scope.objects[name] or { none }
	// } else {
	// 	for child in gen.files[gen.file_count].scope.children {
	// 		if name in child.objects {
	// 			return child.objects[name] or { none }
	// 		}
	// 	}
	// 	return none
	// }

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