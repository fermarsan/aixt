// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module builder

import os
// import v.parser
// import v.ast
import aixt.util


// api_mod_dirs function detects all the modules in API directories
pub fn (mut b Builder) get_api_mod_dirs() []string {
	mut out := []string{}
	for api_path in b.setup.api_paths {
		// api_base_dir := os.join_path(
		// 	aixt_path, os.path_separator, 
		// 	'targets', os.path_separator, 
		// 	api_path, os.path_separator, 'api'
		// )
		api_base_dir := os.norm_path('${b.aixt_path}/targets/${api_path}/api')
		out << api_base_dir
		// out << util.get_subdirs(api_base_dir)
	}
	return out
}

// api_mod_paths function detects all the modules in API directories
pub fn (mut b Builder) get_api_mod_paths() []string {
	mut out := []string{}
	for api_path in b.setup.api_paths {
		// api_path_sub := api_path.replace('.', os.path_separator)
		// println('>>>>>>>>>>>>>>>>>> ${api_path_sub} <<<<<<<<<<<<<<<<<<')
		api_base_dir := os.norm_path('${b.aixt_path}/targets/${api_path}/api')
		mut api_dirs := [api_base_dir]
		api_dirs << util.get_subdirs(api_base_dir)
		// println('>>>>>>>>>>>>>>>>>> ${api_dirs} <<<<<<<<<<<<<<<<<<')
		for folder in api_dirs {
			// println('>>>>>>>>>>>>>>>>>> ${os.base(folder)} <<<<<<<<<<<<<<<<<<')
			for file in b.parsed_files {
				for imp in file.imports {
					mod_main_name := imp.mod.all_before('.')
					mod_subname := imp.mod.all_after('.')
					mod_name := if mod_subname == mod_main_name {
						mod_main_name
					} else {
						imp.mod
					}
					// mod_main_name, mod_subname := imp.mod.split('.')
					// println('>>>>>>>>>>>>>>>>>> ${mod_name} <<<<<<<<<<<<<<<<<<')
					if os.base(folder) == mod_main_name {
						complete_folder := if mod_subname == mod_main_name {
							folder
						} else {
							folder + os.path_separator + mod_subname 
						}
						mut paths :=  b.v_files_from_dir(complete_folder)
						// module_name.c.v first
						for i, path in paths {
							mod_main_file := mod_name.replace('.', '_')
							if path.contains('${mod_main_file}.c.v') {
								paths.delete(i)
								paths.insert(0, path)
								break
							}
						}
						out << paths
					}
				}
			}
			
		}
	}
	// println('>>>>>>>>>>>>>>>>>> ${b.api_mod_paths} <<<<<<<<<<<<<<<<<<')
	return out
}

// lib_mod_paths function detects all the modules in the `lib` folder
pub fn (mut b Builder) get_lib_mod_dirs() []string {
	mut out := []string{}
	// println('\nLibrary modules:')
	lib_paths := os.ls(os.norm_path('${b.aixt_path}/lib')) or { [] } // modules in the `lib` folder
	for lib_path in lib_paths {
		lib_base_dir := os.norm_path('${b.aixt_path}/lib/${lib_path}')
		lib_backend_path := match b.setup.backend {
			'arduino' {
				if os.exists(os.norm_path('${lib_base_dir}/arduino')) {
					os.norm_path('${lib_base_dir}/arduino')
				} else {
					os.norm_path('${lib_base_dir}/c')
				}
			}
			'nxc' {
				if os.exists(os.norm_path('${lib_base_dir}/nxc')) {
					os.norm_path('${lib_base_dir}/nxc')
				} else {
					os.norm_path('${lib_base_dir}/c')	
				}
			}
			else {
				os.norm_path('${lib_base_dir}/c')
			}
		}
		out << lib_backend_path
		// out << util.get_subdirs(lib_backend_path)	
	}
	return out
}

// lib_mod_paths function detects all the modules in the `lib` folder
pub fn (mut b Builder) get_lib_mod_paths() []string {
	mut out := []string{}
	// println('\nLibrary modules:')
	lib_paths := os.ls(os.norm_path('${b.aixt_path}/lib')) or { [] } // modules in the `lib` folder
	for lib_path in lib_paths {
		lib_base_dir := os.norm_path('${b.aixt_path}/lib/${lib_path}')
		lib_backend_path := match b.setup.backend {
			'arduino' {
				if os.exists(os.norm_path('${lib_base_dir}/arduino')) {
					os.norm_path('${lib_base_dir}/arduino')
				} else {
					os.norm_path('${lib_base_dir}/c')
				}
			}
			'nxc' {
				if os.exists(os.norm_path('${lib_base_dir}/nxc')) {
					os.norm_path('${lib_base_dir}/nxc')
				} else {
					os.norm_path('${lib_base_dir}/c')
				}
			}
			else {
				os.norm_path('${lib_base_dir}/c')
			}
		}
		mut lib_dirs := [lib_backend_path]
		lib_dirs << util.get_subdirs(lib_backend_path)	
		// println('>>>>>>>>>>>>>>>>>> ${lib_dirs} <<<<<<<<<<<<<<<<<<')	
		for folder in lib_dirs {
			// println('>>>>>>>>>>>>>>>>>> ${os.base(folder)} <<<<<<<<<<<<<<<<<<')
			for file in b.parsed_files {
				for imp in file.imports {
					lib_name := imp.mod.all_after_last('.')
					$if windows {
						if os.base(folder.all_before_last('\\')) == lib_name {
							mut paths :=  b.v_files_from_dir(folder)
							// library_name.c.v first
							for i, path in paths {
								if path.contains('${lib_name}.c.v') {
									paths.delete(i)
									paths.insert(0, path)
									break
								}
							}
							out << paths
						}
					} $else {
						if os.base(folder.all_before_last('/')) == lib_name {
							mut paths :=  b.v_files_from_dir(folder)
							// library_name.c.v first
							for i, path in paths {
								if path.contains('${lib_name}.c.v') {
									paths.delete(i)
									paths.insert(0, path)
									break
								}
							}
							out << paths
						}
					}
				}
			}
		}
	}
	return out
}

// pub fn (mut b Builder) used_module_paths(node ast.Import, module_map map[string][]string) []string {
// 	mut out := []string{}
// 	if node.mod in module_map {
// 		for module_path in module_map[node.mod] {
// 			if module_path.contains('${node.mod}.c.v') {
// 				out.insert(0, os.abs_path(module_path)) // adds `module_name.c.v`  first
// 			} else {
// 				out << os.abs_path(module_path)
// 			}
// 		}
// 	}
// 	return out
// }

// // import_paths return the file paths of an specific module (import command)
// pub fn (mut b Builder) import_paths(node ast.Import) []string {
// 	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
// 	mut out := []string{}
// 	// println('>>>>>>>>>>>>>>>>>> node.mod: ${node.mod} <<<<<<<<<<<<<<<<<<')
// 	if node.mod in b.api_mod_paths { // API modules
// 		out << b.used_module_paths(node, b.api_mod_paths).reverse() // reverse the order
// 	} else if node.mod in b.lib_mod_paths { // Library modules
// 		out << b.used_module_paths(node, b.lib_mod_paths).reverse() // reverse the order
// 	}
// 	// for path in out {
// 	// 	println(path)
// 	// }
// 	return out
// }

// // add_local_sources recursively finds and adds all the source file paths in a given path
// pub fn (mut b Builder) add_local_sources(global_path string) {
// 	if os.is_file(global_path) { // only one source code
// 		if global_path.ends_with('.v') {
// 			b.source_paths << global_path
// 		}
// 	} else {
// 		for path in util.get_file_paths(global_path) {
// 			b.source_paths << path
// 		}
// 	}
// }

// // find_all_sources recursively finds and adds all the source file paths in a given path
// pub fn (mut b Builder) find_all_sources(n int) {
// 	// println('>>>>>>>>>>>>>>>>>> Files found: ${n} <<<<<<<<<<<<<<<<<<')
// 	mut temp_table := ast.new_table()
// 	temp_files := parser.parse_files(b.source_paths, mut temp_table, b.pref)

// 	// find the import file paths
// 	for file in temp_files { // source folder
// 		for imp in file.imports {
// 			// println('>>>>>>>>>>>>>>>>>> imp: ${imp} <<<<<<<<<<<<<<<<<<')
// 			for path in b.import_paths(imp) {
// 				if path !in b.source_paths {
// 					b.source_paths.insert(1, path)
// 				}
// 			}
// 		}
// 	}

// 	if n != b.source_paths.len {
// 		b.find_all_sources(b.source_paths.len)
// 	}
// }
