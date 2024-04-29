// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

// move_c_lines moves pending lines in output list
fn (mut gen Gen) move_c_lines() {
	for _ in 0 .. gen.movlines_count {
		mut move_index := -1
		for i, line in gen.out {
			if line.contains('//___MOVE_BACK_1___') || line.contains('//___MOVE_BACK_2___') {
				move_index = i
				break
			}
		}
		if move_index != -1 {
			move_line := gen.out[move_index]	// move the line
			gen.out.delete(move_index)
			if move_line.contains('//___MOVE_BACK_1___') {
				gen.out.insert(move_index-1, move_line.replace('//___MOVE_BACK_1___', ''))
			} else if move_line.contains('//___MOVE_BACK_2___') {
				gen.out.insert(move_index-2, move_line.replace('//___MOVE_BACK_2___', ''))
			}
		}
	}
}