// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module builder

import os
import v.ast
import v.parser
import v.checker
// import aixt.util

// parse_files_dir parses one or more Aixt's V sources files,
// this receives the path of an individual source file or a 
// directory and parses all the source files inside
pub fn (mut b Builder) parse_files_dir(path string) {

	// -------------------- Find the main source files --------------------
	mut file_paths := b.v_files_from_dir(os.dir(path))
	// println(path)
	// println(os.dir(path))
	// for file in file_paths {
	// 	println(file)
	// }

	// -------------------- Add the builtin file first --------------------
	api_base_path := os.norm_path('${b.aixt_path}/targets/${b.setup.api_paths[0]}/api') 
	// println('>>>>>>>>>>>>>>>>>> ${api_base_path} <<<<<<<<<<<<<<<<<<')
	if os.exists(os.norm_path('${api_base_path}/builtin.c.v')) {
		file_paths.insert(0, os.norm_path('${api_base_path}/builtin.c.v'))
	} else {
		panic('"builtin.c.v" in have to exist in "${api_base_path}${os.path_separator}"')
	}

	// println('${b.pref.buildmode}')

	println('-------------------- First parser round --------------------\n')
	b.parsed_files = parser.parse_files(file_paths, mut b.table, b.pref)

	println('Source files:\n')
	b.show_parsed_files()

	// -------------------- Load the used API modules' files --------------------
	// b.module_search_paths << b.get_api_mod_dirs()
	// b.module_search_paths << b.get_lib_mod_dirs()			
	file_paths.insert(1, b.get_api_mod_paths())
	file_paths.insert(1, b.get_lib_mod_paths())

	// restart the table
	b.table = ast.new_table()

	println('\n-------------------- Second parser round --------------------\n')
	// b.parse_imports()
	b.parsed_files = parser.parse_files(file_paths, mut b.table, b.pref)

	println('Source files:\n')
	b.show_parsed_files()

	b.checker = checker.new_checker(b.table, b.pref)
	b.checker.check_files(b.parsed_files)
		
	// println('Table imports:')
	// for imp in b.table.imports {
	// 	println('\t${imp}')
	// }

	// println('Table modules:')
	// for mod in b.table.modules {
	// 	println('\t${mod}')
	// }

	// println('Table dumps:')
	// for key, d in b.table.dumps {
	// 	println('\t${key}: ${d}')
	// }

	// println('Table fns:')
	// for key, fnx in b.table.fns {
	// 	println('\t${key}: ${fnx.name}, ${fnx.mod}, ${fnx.file}')
	// }

	// for file in b.parsed_files {
	// 	println(file.path)
	// }
	// for file in b.parsed_files {
	// 	for imp in file.imports {
	// 		println(imp.source_name)
	// 	}
	// }

}