// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module main

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(__linux) || defined(linux)
#define CLEAR_SCREEN    "clear" // for Linux
#else
#define CLEAR_SCREEN    "cls"   // for Windows
#endif 

// init function call setup or initialization code
fn C.init()