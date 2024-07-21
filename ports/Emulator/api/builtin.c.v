// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module main

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "builtin.c"

// init function call setup or initialization code
pub fn init() {
    C.printf('\033[1;37m')    // white bold text in terminal
}