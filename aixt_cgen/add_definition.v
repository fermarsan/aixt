// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// add_definition adds a definition command to the output file.
fn (mut gen Gen) add_definition(def string) {
	if def !in gen.definitions {
		gen.definitions << '${def}\n'
	}
}