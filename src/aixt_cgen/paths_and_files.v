// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import os
import v.ast

// get_files function look for files in a folder recursively
// returns an array of strings with all tha paths of found files
fn get_file_paths(path string) []string {
	mut paths := []string{}
	dir_content := os.ls(path) or { [] }
	for item in dir_content {
		if os.is_dir('${path}/${item}') {
			paths << get_file_paths('${path}/${item}')
		} else {
			paths << '${path}/${item}'
		}
	}
	return paths
}

// load_api_mod_paths function detects all the modules in API folders
fn (mut gen Gen) load_api_mod_paths() {
	// println('API modules:')
	for api_path in gen.setup.api_paths {
		base_dir := '${gen.transpiler_path}/ports/${api_path}/api'
		dir_content := os.ls(base_dir) or { [] }
		for item in dir_content {
			module_path := '${base_dir}/${item}'
			if os.is_dir(module_path) {
				sub_dir_content := os.ls(module_path) or { [] }
				for sub_item in sub_dir_content {
					file_path := '${module_path}/${sub_item}'
					if os.is_file(file_path) && file_path.ends_with('.c.v') {
						gen.api_mod_paths[item] << file_path
					}
				}
			}
		}
	}
	// for item, dirs in gen.api_mod_paths {
	// 	println('  ${item}:\n\t${dirs.join('\n\t')}')
	// }
}

// load_lib_mod_paths function detects all the modules in the `lib` folder
fn (mut gen Gen) load_lib_mod_paths() {
	// println('\nLibrary modules:')
	lib_paths := os.ls('${gen.transpiler_path}/lib') or { [] } // modules in the `lib` folder
	for lib_path in lib_paths {
		base_dir := '${gen.transpiler_path}/lib/${lib_path}'
		lib_backend_path := match gen.setup.backend {
			'arduino' {
				if os.exists('${base_dir}/arduino') {
					'${base_dir}/arduino'
				} else {
					'${base_dir}/c'
				}
			}
			'nxc' {
				if os.exists('${base_dir}/nxc') {
					'${base_dir}/nxc'
				} else {
					'${base_dir}/c'
				}
			}
			else {
				'${base_dir}/c'
			}
		}
		dir_content := os.ls(lib_backend_path) or { [] }
		for item in dir_content {
			file_path := '${lib_backend_path}/${item}'
			if os.is_file(file_path) && file_path.ends_with('.c.v') {
				gen.lib_mod_paths[lib_path] << file_path
			}
		}
	}
	// for item, dirs in gen.lib_mod_paths {
	// 	println('  ${item}:\n\t${dirs.join('\n\t')}')
	// }
}

// add_local_sources recursively finds and adds all the source file paths in a given path
fn (mut gen Gen) add_local_sources(global_path string) {
	if os.is_file(global_path) {	// only one source code
		if global_path.ends_with('.v') {
			gen.source_paths << global_path
		}
	} else {
		paths := os.ls(global_path) or { [] }
		for path in paths {
			gen.add_local_sources('${global_path}/${path}')	// recursively find
		}
	}
}

fn (mut gen Gen) used_module_paths(node ast.Import, module_map map[string][]string) []string {
	mut out := []string{}
	module_short_name := node.mod.all_after_last('.')
	if node.mod in module_map {	
		for module_path in module_map[module_short_name] {
			if module_path.contains('${module_short_name}.c.v') {
				out.insert(0, os.abs_path(module_path))	// adds `module_name.c.v`  first
			} else {
				out << os.abs_path(module_path)
			}
		}	
	}
	return out	
}


// import_paths return the file paths of an specific module (import command)
fn (mut gen Gen) import_paths(node ast.Import) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	module_short_name := node.mod.all_after_last('.')
	if module_short_name in gen.api_mod_paths {	// API modules
		out << gen.used_module_paths(node, gen.api_mod_paths).reverse()	// reverse the order
	} else if module_short_name in gen.lib_mod_paths {	// Library modules
		out << gen.used_module_paths(node, gen.lib_mod_paths).reverse() // reverse the order
	} 
	// else {	// Custom modules
	// 	if node.mod !in gen.imports {	// if the module is not imported yet
	// 		gen.imports << node.mod
	// 		module_path := '${node.mod.replace('.', '/')}'
	// 		// println('############# ${module_short_name} #############')
	// 		if node.syms.len == 0 {
	// 			file_paths := os.ls('${module_path}') or { [] }
	// 			// println(file_paths)
	// 			for file_path in file_paths {
	// 				if file_path.ends_with('.v') { 
	// 					out << os.abs_path('${module_path}/${file_path}')
	// 				}
	// 			}
				// 		} else {
	// 			for s in node.syms {
	// 				out << os.abs_path('${module_path}/${s.name}.v')
	// 			}
	// 		}
	// 	}
	// }
	return out
}