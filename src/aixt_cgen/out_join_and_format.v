// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import regex

// out_join_and_format formats the output file.
fn (mut gen Gen) out_join_and_format() string{
	mut re := regex.new()
	mut temp := ''
	mut ind_count := 0

	// join output C lines
	mut out := gen.out.join('\n')

	// delete multiple unnecessary new-line caracteres
	re.compile_opt('\n\n\n+') or { panic(err) }
	out = re.replace(out, '\n\n')

	// replace ' ;' by ';'

	// add inner-block commands indentation 
	for c in out {
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
	temp = temp.replace('#endif;', '#endif')
	out = temp + '\n'

	return out
}