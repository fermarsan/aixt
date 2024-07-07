// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT

module aixt_cgen

import v.parser
import v.checker

// parse_check_files parses and checks all the current source files.
pub fn (mut gen Gen) parse_check_files() {
	gen.files = parser.parse_files(gen.source_paths, mut gen.table, gen.pref)
	mut checker_ := checker.new_checker(gen.table, gen.pref)
	checker_.check_files(gen.files)
}