// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// out_replacements formats the output file.
fn (mut gen Gen) out_replacements() {
	gen.out = gen.out.map(it.replace('___preprocessor_block___', gen.c_preproc_cmds.join('\n')))
	// gen.out = gen.out.map(it.replace('___includes_block___', gen.includes.join('')))
	// gen.out = gen.out.map(it.replace('___macros_block___', gen.macros.join('')))
	gen.out = gen.out.map(it.replace('___definitions_block___', gen.definitions.join('\n')))
	gen.out = gen.out.map(it.replace('___initialization_block___', gen.init_cmds.join('\n')))
}