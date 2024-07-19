// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module uart2

pub fn println(uart_num int, msg string) {
	C.printf('\033[1;34m')	// blue
    C.printf('%s\n', msg)
}
