// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module build2

import os
import v.ast
// import v.token
import v.pref
import v.builder
import v.parser

import aixt.setup
// import aixt.cgen
import aixt.util

// transpile_file transpiles an Aixt source code into C.
pub fn transpile_file(path string, project_setup setup.Setup) {

	parsed_files := parse_file(path, project_setup)
	err_war_print(parsed_files)

}