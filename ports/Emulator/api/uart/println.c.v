// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module uart

#include "println.c"

pub fn println_x(uart_num int, msg string) {
	if uart_num == 0 {
		C.printf('\033[1;32m')	// green
	} else if uart_num == 1 {
		C.printf('\033[1;34m')	// blue
	} else if uart_num == 2 {
		C.printf('\033[1;31m')	// red
	} else {
		C.printf('\033[0m')		// white
	}
    C.printf('%s\n', msg)
}
