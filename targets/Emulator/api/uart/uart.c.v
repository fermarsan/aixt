// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// Description: input and printing functions.
module uart

#include <stdio.h>
#include <string.h>

__global (
	uart__buffer = ''
)

fn init() {
	C.printf('\033[1;32m')	// print in green
	C.printf(' Aixt virtual UART\n')
}

pub fn print(msg string) {
	C.printf('\033[1;32m')	// green
    C.printf('%s', msg)
}

pub fn println(msg string) {
	C.printf('\033[1;32m')	// green
    C.printf('%s\n', msg)
}

pub fn input(msg string) string {
    C.printf("\033[1;32m")	// print in green
    C.printf("%s ", msg)
    C.scanf("%s", uart__buffer)
    return uart__buffer
}