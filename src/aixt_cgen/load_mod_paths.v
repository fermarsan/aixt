// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module aixt_cgen

import os

// load_mod_paths function detects all the modules in API folders
fn (mut gen Gen) load_mod_paths() {
	api_paths := gen.setup.api_paths
	// println('${api_paths}')
	for api_path in api_paths {
		base_dir := '${gen.transpiler_path}/ports/${api_path}/api'
		dir_content := os.ls(base_dir) or { [] }
		for item in dir_content {
			if os.is_dir(os.join_path(base_dir, item)) {
				gen.api_mod_paths[item] = '${base_dir}/${item}'
			}
		}
	}
	for item, dir in gen.api_mod_paths {
		println('  ${item}: ${dir}')
	}
}

