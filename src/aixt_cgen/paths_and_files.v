// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import os
import v.ast

// load_mod_paths function detects all the modules in API folders
fn (mut gen Gen) load_mod_paths() {
	api_paths := gen.setup.api_paths
	// println('${api_paths}')
	for api_path in api_paths {
		base_dir := '${gen.transpiler_path}/ports/${api_path}/api'
		dir_content := os.ls(base_dir) or { [] }
		for item in dir_content {
			if os.is_dir(os.join_path(base_dir, item)) {
				gen.api_mod_paths[item] = '${base_dir}/${item}'
			}
		}
	}
	for item, dir in gen.api_mod_paths {
		println('  ${item}: ${dir}')
	}
}


// add_sources recursively finds and adds all the source file paths in a given path
fn (mut gen Gen) add_sources(global_path string) {
	if os.is_file(global_path) {	// only one source code
		if global_path.ends_with('.v') {	//|| global_path.ends_with('.aixt') {
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
	if module_short_name in gen.api_mod_paths {	// API modules
		module_path := gen.api_mod_paths[module_short_name]
		if os.exists('${module_path}/${module_short_name}.c.v') {
			out << '${module_path}/${module_short_name}.c.v'	// adds `module_name.c.v`  first
		}
		if node.syms.len == 0 {	// if import all the module
			file_paths := os.ls('${module_path}') or { [] }
			// println('############# ${file_paths} #############')
			for file_path in file_paths {
				if file_path.ends_with('.c.v') { // || file_path.ends_with('.aixt') {
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
	} else {	// Custom modules
		module_path := '${node.mod.replace('.', '/')}'
		// println('############# ${module_short_name} #############')
		if node.syms.len == 0 {
			file_paths := os.ls('${module_path}') or { [] }
			// println(file_paths)
			for file_path in file_paths {
				if file_path.ends_with('.v') { // || file_path.ends_with('.aixt') {
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