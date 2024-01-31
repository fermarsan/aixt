// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

// find_sources recursively finds all the source file paths in a given path
fn (mut gen Gen) find_sources(global_path string) {
	if os.is_file(global_path) {	// only one source code
		gen.src_paths << global_path
	} else {
		paths := os.ls(global_path) or { [] }
		for path in paths {
			if os.is_file(path) {
				if path.contains('.v') || path.contains('.aixt') {
					gen.src_paths << path
				}
			} else {
				gen.find_sources(path)	// recursively find
			}
		}
	}
}