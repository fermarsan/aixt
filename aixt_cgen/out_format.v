// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

// out_format formats the output file.
fn (mut gen Gen) out_format() {
	gen.out = gen.out.replace('___includes_block___', gen.headers)
	gen.out = gen.out.replace('___macros_block___', gen.macros)
	gen.out = gen.out.replace('___definitions_block___', gen.defs)
	gen.out = gen.out.replace('\n\n\n\n\n', '\n\n')
	gen.out = gen.out.replace('\n\n\n\n', '\n\n')
	gen.out = gen.out.replace('\n\n\n', '\n\n')
	gen.out = gen.out.replace('\n\n\n;', '\n')
	gen.out = gen.out.replace('\n\n;', '\n---')
	gen.out = gen.out.replace('}\n;', '}')
	mut temp := ''
	mut ind_count := 0
	for c in gen.out {
		match rune(c) {
			`\n` {
				temp += '\n' + '\t'.repeat(ind_count)
			}
			`{` {
				ind_count++
				temp += rune(c).str()
			}
			`}` {
				ind_count--
				temp += rune(c).str()
			}
			else {
				temp += rune(c).str()
			}
		}
	}
	temp = temp.replace('\t}', '}')
	gen.out = temp + '\n'
}