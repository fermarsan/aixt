// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import os
import v.ast

// load_mod_paths function detects all the modules in API folders
fn (mut gen Gen) load_mod_paths() {
	// println('>>>>>>>>>>>>>>>>>> ${gen.setup.api_paths} <<<<<<<<<<<<<<<<<<')
	println('Module paths:')
	api_paths := gen.setup.api_paths
	// println('${api_paths}')
	for api_path in api_paths {
		base_dir := '${gen.transpiler_path}/ports/${api_path}/api'
		dir_content := os.ls(base_dir) or { [] }
		for item in dir_content {
			if os.is_dir(os.join_path(base_dir, item)) {
				gen.api_mod_paths[item] << '${base_dir}/${item}'
			}
		}
	}
	for item, dirs in gen.api_mod_paths {
		println('  ${item}:\n\t${dirs.join('\n\t')}')
	}
}


// add_sources recursively finds and adds all the source file paths in a given path
fn (mut gen Gen) add_sources(global_path string) {
	if os.is_file(global_path) {	// only one source code
		if global_path.ends_with('.v') {
			gen.source_paths << global_path
		}
	} else {
		paths := os.ls(global_path) or { [] }
		for path in paths {
			gen.add_sources('${global_path}/${path}')	// recursively find
		}
	}
}

// import_paths return the file paths of an specific module (import command)
fn (mut gen Gen) import_paths(node ast.Import) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	module_short_name := node.mod.all_after_last('.')
	lib_mod_paths := os.ls('${gen.transpiler_path}/lib/') or { [] }
	// println('>>>>>>>>>>>>>>>>>> ${lib_mod_paths} <<<<<<<<<<<<<<<<<<')
	if module_short_name in gen.api_mod_paths {	// API modules
		for module_path in gen.api_mod_paths[module_short_name] {
			if os.exists('${module_path}/${module_short_name}.c.v') {
				out << '${module_path}/${module_short_name}.c.v'	// adds `module_name.c.v`  first
			}
			if node.syms.len == 0 {	// if import all the module
				file_paths := os.ls('${module_path}') or { [] }
				// println('############# ${file_paths} #############')
				for file_path in file_paths {
					if file_path.ends_with('.c.v') {
						if file_path != '${module_short_name}.c.v' {	// ommit `module_name.c.v` 
							out << os.abs_path('${module_path}/${file_path}')
						}			
					}
				}
			} else {	// if import specific module components
				for s in node.syms {
					out << os.abs_path('${module_path}/${s.name}.c.v')
				}
			}
		}
	} else if module_short_name in lib_mod_paths {	// Library modules
		lib_path := match gen.setup.backend {
			'arduino' {
				if os.exists('${gen.transpiler_path}/lib/${module_short_name}/arduino/') {
					'${gen.transpiler_path}/lib/${module_short_name}/arduino/'
				} else {
					'${gen.transpiler_path}/lib/${module_short_name}/c'
				}
			}
			'nxc' {
				if os.exists('${gen.transpiler_path}/lib/${module_short_name}/nxc/') {
					'${gen.transpiler_path}/lib/${module_short_name}/nxc/'
				} else {
					'${gen.transpiler_path}/lib/${module_short_name}/c'
				}
			}
			else {
				'${gen.transpiler_path}/lib/${module_short_name}/c'
			}
		}
		if os.exists('${lib_path}/${module_short_name}.c.v') {
			out << '${lib_path}/${module_short_name}.c.v'	// adds `module_name.c.v`  first
		}
		if node.syms.len == 0 {	// if import all the module
			file_paths := os.ls('${lib_path}') or { [] }
			// println('############# ${file_paths} #############')
			for file_path in file_paths {
				if file_path.ends_with('.c.v') {
					if file_path != '${module_short_name}.c.v' {	// ommit `module_name.c.v` 
						out << os.abs_path('${lib_path}/${file_path}')
					}			
				}
			}
		} else {	// if import specific module components
			for s in node.syms {
				out << os.abs_path('${lib_path}/${s.name}.c.v')
			}
		}
	} else {	// Custom modules
		module_path := '${node.mod.replace('.', '/')}'
		// println('############# ${module_short_name} #############')
		if node.syms.len == 0 {
			file_paths := os.ls('${module_path}') or { [] }
			// println(file_paths)
			for file_path in file_paths {
				if file_path.ends_with('.v') { 
					out << os.abs_path('${module_path}/${file_path}')
				}
			}
		} else {
			for s in node.syms {
				out << os.abs_path('${module_path}/${s.name}.v')
			}
		}
	}
	return out
}