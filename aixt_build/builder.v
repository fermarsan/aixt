// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// it is governed by an MIT license (MIT)
// Copyright (c) 2023 Fernando Martínez Santa
module aixt_build

import os
import toml
import v.ast
import v.pref
import aixt_cgen

pub fn build_file(path string, setup_file toml.Doc) {
	mut c_gen := aixt_cgen.Gen{
		file:	&ast.File{}
		table:	ast.new_table()
		out:	''
		pref:	&pref.Preferences{}
		setup:	toml.Doc{}
	}
	
	c_gen.pref.is_script = true
	c_gen.setup = setup_file

	transpiled := c_gen.gen(path)	// transpile Aixt (V) to C

	// saves the output file
	output_ext := if c_gen.setup.value('backend').string() == 'nxc' { '.nxc' } else { '.c' }
	output_path := path.replace('.v', output_ext)
	os.write_file(output_path, transpiled) or {}

	// // mut trans_code := c_embedded.gen(tree)
	// mut trans_code := ''
	// if os.args.len > 2 {
	// 	if os.args[2] == '-nxc' { // if -nxt flag
	// 		equivalents := toml.parse_file('../api/equivalents.toml') or {
	// 			panic('file does not exist. ')
	// 		}
	// 		for eq in equivalents.to_any().as_map().keys() {
	// 			trans_code = trans_code.replace(eq, equivalents.value(eq).string()) // replace the NXC equivalents
	// 		}
	// 	} else {
	// 		println('Invalid flag.\n')
	// 	}
	// }
	// println(trans_code)
	// println('_'.repeat(60) + '\n')

}

// pub fn build_api(path string) {
// 	file_list := os.walk_ext(path, '.aixt') // transpile secondary files
// 	for file in file_list {
// 		// if file != input_name {
// 		println('Building API........') // os.execute('v run ${aixt_builder} ${device} ${file}').output)
// 		// }
// 	}
// }
