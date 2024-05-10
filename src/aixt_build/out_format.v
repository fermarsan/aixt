// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_build

import regex

// out_replacements formats the output file.
pub fn out_format(output_code string) string{
	mut out := ''
	mut re1 := regex.regex_opt(r'\\n\\t') or { panic(err) }
	out = re1.replace(output_code, r'\\n')
	println(out)
	
	// gen.out = gen.out.map(it.replace('\n\n\n\n\n', '\n\n'))
	// gen.out = gen.out.map(it.replace('\n\n\n\n', '\n\n'))
	// gen.out = gen.out.map(it.replace('\n\n\n', '\n\n'))
	// gen.out = gen.out.map(it.replace('\n\n\n;', '\n'))
	// gen.out = gen.out.map(it.replace('\n\n;', '\n---'))
	// gen.out = gen.out.map(it.replace('}\n;', '}'))
	// mut temp := ''
	// mut ind_count := 0
	// for c in gen.out {
	// 	match rune(c) {
	// 		`\n` {
	// 			temp += '\n' + '\t'.repeat(ind_count)
	// 		}
	// 		`{` {
	// 			ind_count++
	// 			temp += rune(c).str()
	// 		}
	// 		`}` {
	// 			ind_count--
	// 			temp += rune(c).str()
	// 		}
	// 		else {
	// 			temp += rune(c).str()
	// 		}
	// 	}
	// }
	// temp = temp.replace('\t}', '}')
	// gen.out = temp + '\n'
	return ''
}