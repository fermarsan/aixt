// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module builder

import os
import v.parser
import aixt.util

// parse_files_dir parses one or more Aixt's V sources files,
// this receives the path of an individual source file or a 
// directory and parses all the source files inside
pub fn (mut b Builder) parse_files_dir(path string) {

	// -------------------- Find the main source files --------------------
	mut file_paths := b.v_files_from_dir(os.dir(path))

	// -------------------- First parser round --------------------
	b.parsed_files = parser.parse_files(file_paths, mut b.table, b.pref)

	for file in b.parsed_files {
		println(file.path)
	}

	// load the API modules' paths
	for api_path in b.setup.api_paths {
		// base_dir := os.join_path(
		// 	aixt_path, os.path_separator, 
		// 	'ports', os.path_separator, 
		// 	api_path, os.path_separator, 'api'
		// )
		base_dir := '${b.aixt_path}/ports/${api_path}/api'
		mut api_dirs := [base_dir]
		api_dirs << util.get_subdirs(base_dir)
		// println('>>>>>>>>>>>>>>>>>> ${api_dirs} <<<<<<<<<<<<<<<<<<')
		for folder in api_dirs {
			// println('>>>>>>>>>>>>>>>>>> ${os.base(folder)} <<<<<<<<<<<<<<<<<<')
			for file in b.parsed_files {
				for imp in file.imports {
					if os.base(folder) == imp.mod.all_after_last('.') {
						file_paths << b.v_files_from_dir(folder)
					}
				}
			}
			
		}
	}

	// -------------------- Second parser round --------------------
	b.parsed_files = parser.parse_files(file_paths, mut b.table, b.pref)

	for file in b.parsed_files {
		println(file.path)
	}

	// println('>>>>>>>>>>>>>>>>>> ${aixt_path} <<<<<<<<<<<<<<<<<<')

	// // set de defines from the port's json file
	// mut defines := ['']
	// for define in c_gen.setup.v_defines {
	// 	defines << ['-d', define]
	// }
	// // println('-------------------- ${defines} --------------------------')
	// c_gen.pref, _ = pref.parse_args_and_show_errors([], defines, true)
	// c_gen.pref.is_script = true
	// c_gen.pref.enable_globals = true
	// // c_gen.pref.experimental = true	//XXXXXXXXXXXXXXXXX DISABLE for V compiler v0.4.9+ (avoid manual C functions declaration) XXXXXXXXXXXXXXXXX 
	
	// // println('##################### ${c_gen.pref.compile_values} ########################')


	// // println('\n\n+++++++${path}++++++++\n\n')
	// mut transpiled := c_gen.gen(path) // transpile Aixt (V) to C

	// if transpiled != '' {
	// 	output_ext := match c_gen.setup.backend {
	// 		'nxc' 		{ '.nxc' }
	// 		'arduino'	{ '.ino' }
	// 		else 		{ '.c' }
	// 	}

	// 	mut output_path := ''
	// 	if os.is_file(path) {
	// 		output_path = path.replace('.v', output_ext)
	// 	} else {
	// 		output_path = '${path}/main${output_ext}'
	// 	}
	// 	os.write_file(output_path, transpiled) or {}
	// }
	// // println('##################### ${c_gen.pref.compile_values} ########################')
}