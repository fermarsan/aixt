// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module main

#include <stdbool.h>
#include <stdlib.h>

#if defined(__linux) || defined(linux)
#define CLEAR_SCREEN    "clear" // for Linux
#else
#define CLEAR_SCREEN    "cls"   // for Windows
#endif 

// Pin_names is the enumerated type for the pin names
enum Pin_names {
    a = 0   
    b
    c
    d
    w
    x
    y
    z
}

// init function call setup or initialization code
fn init() {
    printf('\033[1;37m')    // white bold text in terminal
}