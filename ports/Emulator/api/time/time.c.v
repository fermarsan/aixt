// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module time

// #include <time.h>
#if defined(__linux) || defined(linux)
#include <unistd.h>
#else
#include <windows.h>
#endif

// __global (
// 	start_time i64
// )

fn init() {

}