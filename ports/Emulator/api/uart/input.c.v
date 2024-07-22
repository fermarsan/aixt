// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module uart

pub fn input(msg string) string {
	mut buffer := ''
    C.printf("\033[1;32m")	// print in green
    C.printf("%s ", msg)
    C.scanf("%s", buffer)
    return buffer
}