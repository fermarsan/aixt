// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import os
import v.ast

// import_stmt is the code generation function for import statements.
fn (mut gen Gen) import_stmt(node ast.Import) string {
	// println('${gen.setup.value('port').string()}')
	base_mod_name := node.mod.after('.')
	port_path := gen.setup.value('path').string()
	api_modules := gen.setup.value('api_modules').array().as_strings()

	if base_mod_name in api_modules {	// API modules
		module_path := '${gen.transpiler_path}/ports/${port_path}/api/${base_mod_name}'	
		gen.parse_cgen_file('${module_path}/${base_mod_name}.c.v')	// parse `module_name.c.v` first
		gen.init_cmds += '${base_mod_name}__init();\n'	// call the module initialization function
		if node.syms.len == 0 {	// if import all the module
			file_paths := os.ls('${module_path}') or { [] }
			// println('############# ${file_paths} #############')
			for file_path in file_paths {
				if file_path.ends_with('.c.v') { // || file_path.ends_with('.aixt') {
					if file_path != '${base_mod_name}.c.v' {	// ommit `module_name.c.v`
						gen.parse_cgen_file(os.abs_path('${module_path}/${file_path}'))
					}
				}
			}
		} else {	// if import specific module components
			for s in node.syms {
				gen.parse_cgen_file(os.abs_path('${module_path}/${s.name}.c.v'))
			}
		}
	} else {	// Custom modules
		module_path := '${node.mod.replace('.', '/')}'
		// println('############# ${base_mod_name} #############')
		if node.syms.len == 0 {
			file_paths := os.ls('${module_path}') or { [] }
			// println(file_paths)
			for file_path in file_paths {
				if file_path.ends_with('.v') { // || file_path.ends_with('.aixt') {
					gen.parse_cgen_file(os.abs_path('${module_path}/${file_path}'))
				}
			}
		} else {
			for s in node.syms {
				gen.parse_cgen_file(os.abs_path('${module_path}/${s.name}.v'))
			}
		}
	}

	return ''
}