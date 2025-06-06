// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import os
import v.parser
import v.ast

// get_files function look for file paths in a folder recursively
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
		base_dir := '${gen.aixt_path}/ports/${api_path}/api'
		for path in get_file_paths(base_dir) {
			short_path := path.replace('${base_dir}/', '')
			if short_path.ends_with('.c.v') {
				module_name := if short_path.contains('/') {
					short_path.all_before_last('/').replace('/', '.')
				} else {
					'main'
				}
				gen.api_mod_paths[module_name] << path
			}
		}
	}
	// for item, dirs in gen.api_mod_paths {
	// 	println('  ${item}:\n\t${dirs.join('\n\t')}')
	// }
	// println('>>>>>>>>>>>>>>>>>> ${gen.api_mod_paths} <<<<<<<<<<<<<<<<<<')
	// println('>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>')
	// for mod, paths in gen.api_mod_paths {
	// 	println('${mod} :\n${paths}')
	// }
	// println('<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<')
}

// load_lib_mod_paths function detects all the modules in the `lib` folder
fn (mut gen Gen) load_lib_mod_paths() {
	// println('\nLibrary modules:')
	lib_paths := os.ls('${gen.aixt_path}/lib') or { [] } // modules in the `lib` folder
	for lib_path in lib_paths {
		base_dir := '${gen.aixt_path}/lib/${lib_path}'
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

fn (mut gen Gen) used_module_paths(node ast.Import, module_map map[string][]string) []string {
	mut out := []string{}
	if node.mod in module_map {
		for module_path in module_map[node.mod] {
			if module_path.contains('${node.mod}.c.v') {
				out.insert(0, os.abs_path(module_path)) // adds `module_name.c.v`  first
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
	// println('>>>>>>>>>>>>>>>>>> node.mod: ${node.mod} <<<<<<<<<<<<<<<<<<')
	if node.mod in gen.api_mod_paths { // API modules
		out << gen.used_module_paths(node, gen.api_mod_paths).reverse() // reverse the order
	} else if node.mod in gen.lib_mod_paths { // Library modules
		out << gen.used_module_paths(node, gen.lib_mod_paths).reverse() // reverse the order
	}
	// for path in out {
	// 	println(path)
	// }
	return out
}

// add_local_sources recursively finds and adds all the source file paths in a given path
fn (mut gen Gen) add_local_sources(global_path string) {
	if os.is_file(global_path) { // only one source code
		if global_path.ends_with('.v') {
			gen.source_paths << global_path
		}
	} else {
		for path in get_file_paths(global_path) {
			gen.source_paths << path
		}
	}
}

// find_all_sources recursively finds and adds all the source file paths in a given path
pub fn (mut gen Gen) find_all_sources(n int) {
	// println('>>>>>>>>>>>>>>>>>> Files found: ${n} <<<<<<<<<<<<<<<<<<')
	mut temp_table := ast.new_table()
	temp_files := parser.parse_files(gen.source_paths, mut temp_table, gen.pref)

	// find the import file paths
	for file in temp_files { // source folder
		for imp in file.imports {
			// println('>>>>>>>>>>>>>>>>>> imp: ${imp} <<<<<<<<<<<<<<<<<<')
			for path in gen.import_paths(imp) {
				if path !in gen.source_paths {
					gen.source_paths.insert(1, path)
				}
			}
		}
	}

	if n != gen.source_paths.len {
		gen.find_all_sources(gen.source_paths.len)
	}
}
