// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.parser

// find_all_source_files adds all the source files paths (recursively)
// to the list
pub fn (mut gen Gen) find_all_source_files(source_path string) {
	println('~'.repeat(70))
	// main module builtin source file
	port_path := gen.setup.value('path').string()
	gen.source_paths << '${gen.transpiler_path}/ports/${port_path}/api/builtin.c.v'

	gen.add_sources(source_path)	// main source folder

	gen.files = parser.parse_files(gen.source_paths, mut gen.table, gen.pref)

	println('\n===== Top-down node analysis (Parsing) =====')
	gen.code_gen = false
	temp_files := gen.files
	for file in temp_files {	// source folder
		gen.ast_node(file)	// starts from the main node (file)
	}

	println('\nmain source files:')	//  print source files
	for source in gen.source_paths {
		println('\t${source}')
	}
	println('~'.repeat(70))
}