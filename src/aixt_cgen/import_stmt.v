// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import os
import v.ast

// import_stmt is the code generation function for import statements.
fn (mut gen Gen) import_stmt(node ast.Import) []string {
	if node.mod !in gen.imports {
		gen.imports << node.mod
		// println('############# ${gen.imports} #############')
		module_short_name := node.mod.all_after_last('.')
		port_path := gen.setup.value('path').string()
		api_modules := gen.setup.value('api_modules').array().as_strings()

		if module_short_name in api_modules {	// API modules
			// if module_short_name !in gen.table.imports {	// avoid repeats importing
			module_path := '${gen.transpiler_path}/ports/${port_path}/api/${module_short_name}'	
			gen.parse_module_file('${module_path}/${module_short_name}.c.v')	// parse `module_name.c.v` first
			// gen.init_cmds += '${module_short_name}__init();\n'	// call the module initialization function
			if node.syms.len == 0 {	// if import all the module
				file_paths := os.ls('${module_path}') or { [] }
				// println('############# ${file_paths} #############')
				for file_path in file_paths {
					if file_path.ends_with('.c.v') { // || file_path.ends_with('.aixt') {
						if file_path != '${module_short_name}.c.v' {	// ommit `module_name.c.v`
							gen.parse_module_file(os.abs_path('${module_path}/${file_path}'))
						}			
					}
				}
			} else {	// if import specific module components
				for s in node.syms {
					gen.parse_module_file(os.abs_path('${module_path}/${s.name}.c.v'))
				}
			}
			// }
		} else {	// Custom modules
			module_path := '${node.mod.replace('.', '/')}'
			// println('############# ${module_short_name} #############')
			if node.syms.len == 0 {
				file_paths := os.ls('${module_path}') or { [] }
				// println(file_paths)
				for file_path in file_paths {
					if file_path.ends_with('.v') { // || file_path.ends_with('.aixt') {
						gen.parse_module_file(os.abs_path('${module_path}/${file_path}'))
					}
				}
			} else {
				for s in node.syms {
					gen.parse_module_file(os.abs_path('${module_path}/${s.name}.v'))
				}
			}
		}
	}
	return []
}