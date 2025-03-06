// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// import os
import v.ast
// import v.parser
// import v.checker

// import_stmt is the code generation function for import statements.
fn (mut gen Gen) import_stmt(node ast.Import) []string {
	// println('>>>>>>>>>>>>>>>>>> Import: ${node.mod} <<<<<<<<<<<<<<<<<<')
	// gen.source_paths.insert(1, gen.import_paths(node))
	return []
}

// // parse_module_file, parces and generates code from a new source file
// // this is used mainly for modules
// pub fn (mut gen Gen) parse_module_file(source_path string) []string {
// 	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')

// 	mut checker_ := checker.new_checker(gen.table, gen.pref)
	
// 	gen.source_paths << source_path

// 	// $if windows {
// 	//	file = parser.parse_file(source_path, mut gen.table, .skip_comments, gen.pref)
// 	// } $else {
// 	// 	file = parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
// 	// }
// 	file := parser.parse_file(source_path, mut gen.table, .skip_comments, gen.pref)
// 	gen.files << file

// 	checker_.check_files(gen.files)

// 	println('\n===== Top-down node analysis (module) =====')
// 	gen.out << gen.ast_node(file) // starts from the main node (file)

// 	return ['']
// }