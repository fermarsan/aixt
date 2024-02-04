// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
#include <unistd.h>

// sleep_ms is a delay function in milliseconds for the Aixt PC port. 
fn sleep_ms(tms u32) {
  usleep(tms * 1000)
}