// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

// insert_c_lines inserts pending lines in output list
fn (mut gen Gen) insert_c_lines() {
	// println('-------- ${gen.to_insert_lines} --------')
	for i, to_insert_line in gen.to_insert_lines {
		mut insert_index := -1
		for j, line in gen.out {
			if line.contains('___TO_INSERT_${i}___') {
				insert_index = j
				break
			}
		}
		if insert_index != -1 {
			gen.out[insert_index] = gen.out[insert_index].replace('___TO_INSERT_${i}___', '')
			gen.out.insert(insert_index, to_insert_line)
		}
	}
}