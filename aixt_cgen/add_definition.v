// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: add_definition.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: add a definition command in the out file.
module aixt_cgen

fn (mut gen Gen) add_definition(def string) {
	if !gen.definitions.contains(def) {
		gen.definitions += '${def}\n'
	}
}