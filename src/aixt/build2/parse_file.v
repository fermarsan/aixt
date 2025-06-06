// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module build2

import os
import v.ast
import v.pref
import v.builder
import v.parser

import aixt.setup
import aixt.util

// parse_file parses an Aixt source code.
pub fn parse_file(path string, project_setup setup.Setup) []&ast.File {

	aixt_path := os.dir(os.executable())

	mut aixt_pref := &pref.Preferences{}
	// mut aixt_pref, _ := pref.parse_args_and_show_errors([], defines, true)
	aixt_pref.is_script = true
	aixt_pref.enable_globals = true

	mut aixt_builder := builder.new_builder(aixt_pref)
	aixt_builder.table = ast.new_table()

	mut file_paths := aixt_builder.v_files_from_dir(os.dir(path))

	// -------------------- First parser round --------------------
	mut parsed_files := parser.parse_files(file_paths, mut aixt_builder.table, aixt_builder.pref)

	for file in parsed_files {
		println(file.path)
	}

	// load the API modules' paths
	for api_path in project_setup.api_paths {
		// base_dir := os.join_path(
		// 	aixt_path, os.path_separator, 
		// 	'ports', os.path_separator, 
		// 	api_path, os.path_separator, 'api'
		// )
		base_dir := '${aixt_path}/ports/${api_path}/api'
		mut api_folders := [base_dir]
		api_folders << util.get_subfolders(base_dir)
		// println('>>>>>>>>>>>>>>>>>> ${api_folders} <<<<<<<<<<<<<<<<<<')
		for folder in api_folders {
			// println('>>>>>>>>>>>>>>>>>> ${os.base(folder)} <<<<<<<<<<<<<<<<<<')
			for file in parsed_files {
				for imp in file.imports {
					if os.base(folder) == imp.mod.all_after_last('.') {
						file_paths << aixt_builder.v_files_from_dir(folder)
					}
				}
			}
			
		}
	}

	// -------------------- Second parser round --------------------
	parsed_files = parser.parse_files(file_paths, mut aixt_builder.table, aixt_builder.pref)

	for file in parsed_files {
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