// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: input and printing functions.
module uart

#include <stdio.h>
#include <string.h>

// #define OUT = os__input(IN) 

// char *input(char *msg) {
//     printf("%s", msg);
//     scanf("%s", &__temp_str[0]);
//     return __temp_str;
// }

fn init() {
	printf('\033[0;32m')	// print in green
	printf('UART 0\t')
	printf('\033[0;31m')	// print in red
	printf('UART 1\n')
	printf('\033[0;31m')	// come back to black
}