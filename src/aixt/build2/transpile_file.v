// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module build2

import os
import v.ast
import v.token
import v.pref
import v.builder
import v.parser

import aixt.setup
import aixt.cgen

// transpile_file transpiles an Aixt source code into C.
pub fn transpile_file(path string, project_setup setup.Setup, aixt_path string) {

	mut aixt_pref := &pref.Preferences{}
	// mut aixt_pref, _ := pref.parse_args_and_show_errors([], defines, true)
	aixt_pref.is_script = true
	aixt_pref.enable_globals = true

	mut aixt_builder := builder.new_builder(aixt_pref)
	aixt_builder.table = ast.new_table()
	
	scope := ast.Scope{
		parent: unsafe { nil }
	}

	file_paths := aixt_builder.v_files_from_dir(os.dir(path))

	// -------------------- First parser round --------------------
	parsed_files := parser.parse_files(file_paths, mut aixt_builder.table, aixt_builder.pref)

	// println('>>>>>>>>>>>>>>>>>> ${parsed_files} <<<<<<<<<<<<<<<<<<')
	for file in parsed_files {
		println('${os.base(file.path)}:')
		for imp in file.imports {
			println('\t${imp.mod}')
		}
	}


	println('>>>>>>>>>>>>>>>>>> ${pref.vexe_path()} <<<<<<<<<<<<<<<<<<')
	
	println('>>>>>>>>>>>>>>>>>> ${	os.executable()} <<<<<<<<<<<<<<<<<<')

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


// load_api_mod_paths function detects all the modules in API folders
// fn (mut gen Gen) load_api_mod_paths() {
// 	// println('API modules:')
// 	for api_path in gen.setup.api_paths {
// 		base_dir := '${gen.aixt_path}/ports/${api_path}/api'
// 		for path in get_file_paths(base_dir) {
// 			short_path := path.replace('${base_dir}/', '')
// 			if short_path.ends_with('.c.v') {
// 				module_name := if short_path.contains('/') {
// 					short_path.all_before_last('/').replace('/', '.')
// 				} else {
// 					'main'
// 				}
// 				gen.api_mod_paths[module_name] << path
// 			}
// 		}
// 	}
	// for item, dirs in gen.api_mod_paths {
	// 	println('  ${item}:\n\t${dirs.join('\n\t')}')
	// }
	// println('>>>>>>>>>>>>>>>>>> ${gen.api_mod_paths} <<<<<<<<<<<<<<<<<<')
	// println('>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>')
	// for mod, paths in gen.api_mod_paths {
	// 	println('${mod} :\n${paths}')
	// }
	// println('<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<')
// }