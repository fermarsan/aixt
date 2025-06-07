// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module builder

import os
import v.ast
import v.pref
import v.builder as v_builder
import aixt.setup

// transpile_file transpiles an Aixt source code into C.
pub fn transpile_file(path string, project_setup setup.Setup) {

	aixt_path := os.dir(os.executable())

	mut aixt_pref := &pref.Preferences{}
	// mut aixt_pref, _ := pref.parse_args_and_show_errors([], defines, true)
	aixt_pref.is_script = true
	aixt_pref.enable_globals = true

	mut aixt_builder := Builder {
		Builder:	v_builder.new_builder(aixt_pref)
		setup:		project_setup
		aixt_path:	aixt_path
	}
	aixt_builder.table = ast.new_table()

	aixt_builder.parse_files_dir(path)
	aixt_builder.err_war_print()

}