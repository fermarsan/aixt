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

	// -------------------- First parser round --------------------
	b.parsed_files = parser.parse_files(file_paths, mut b.table, b.pref)

	// for file in b.parsed_files {
	// 	println(file.path)
	// }

	// -------------------- Load the used API modules' files --------------------
	// file_paths << b.get_lib_mod_paths()
	file_paths.insert(0, b.get_lib_mod_paths())
	file_paths.insert(0, b.get_api_mod_paths())

	// -------------------- Second parser round --------------------
	b.parsed_files = parser.parse_files(file_paths, mut b.table, b.pref)

	mut checker_ := checker.new_checker(b.table, b.pref)
	checker_.check_files(b.parsed_files)

	println('Source files:')
	for file in b.parsed_files {
		println('\t${file.path}')
	}
}