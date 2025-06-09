// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module builder

import os
import v.parser
import v.checker
// import aixt.util

// parse_files_dir parses one or more Aixt's V sources files,
// this receives the path of an individual source file or a 
// directory and parses all the source files inside
pub fn (mut b Builder) parse_files_dir(path string) {

	// -------------------- Find the main source files --------------------
	mut file_paths := b.v_files_from_dir(os.dir(path))

	// -------------------- Add the builtin file first --------------------
	api_base_path := '${b.aixt_path}/ports/${b.setup.api_paths[0]}/api' 
	if os.exists('${api_base_path}/builtin.c.v') {
		file_paths.insert(0, '${api_base_path}/builtin.c.v')
	} else {
		panic('"builtin.c.v" in have to exist in "${api_base_path}/"')
	}

	println('${b.pref.buildmode}')

	// -------------------- First parser round --------------------
	b.parsed_files = parser.parse_files(file_paths, mut b.table, b.pref)
	// for file in b.parsed_files {
	// 	println(file.path)
	// }
	// for file in b.parsed_files {
	// 	for imp in file.imports {
	// 		println(imp.source_name)
	// 	}
	// }

	// -------------------- Load the used API modules' files --------------------
	b.module_search_paths << b.get_api_mod_dirs()
	b.module_search_paths << b.get_lib_mod_dirs()

	// -------------------- Second parser round --------------------
	println('>>>>>>>>>>>>>>>>>> ${b.module_search_paths} <<<<<<<<<<<<<<<<<<')
	b.parse_imports()

	b.checker = checker.new_checker(b.table, b.pref)
	b.checker.check_files(b.parsed_files)

	println('Source files:')
	for file in b.parsed_files {
		println('\t${file.path}')
		// println('\tt${file.mod}:\n\t${file.path}')
	}
		
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

}