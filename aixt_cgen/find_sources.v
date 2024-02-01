// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import os

// find_sources recursively finds all the source file paths in a given path
fn (mut gen Gen) find_sources(global_path string) {
	if os.is_file(global_path) {	// only one source code
		if global_path.ends_with('.v') || global_path.ends_with('.aixt') {
			gen.src_paths << global_path
		}
	} else {
		paths := os.ls(global_path) or { [] }
		for path in paths {
			gen.find_sources('${global_path}/${path}')	// recursively find
		}
	}
}