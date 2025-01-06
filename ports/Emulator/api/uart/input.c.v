// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart

pub fn input(msg string) string {
    C.printf("\033[1;32m")	// print in green
    C.printf("%s ", msg)
    C.scanf("%s", uart__buffer)
    return uart__buffer
}