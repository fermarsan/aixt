// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// Description: input and printing functions.
module uart2

#include <stdio.h>
#include <string.h>

fn init() {
	C.printf('\033[1;34m')	// Print in blue
	C.printf(' Aixt virtual UART 2\n')
}

pub fn print(msg string) {
	C.printf('\033[1;34m')	// blue
    C.printf('%s', msg)
}

pub fn println(msg string) {
	C.printf('\033[1;34m')	// blue
    C.printf('%s\n', msg)
}
