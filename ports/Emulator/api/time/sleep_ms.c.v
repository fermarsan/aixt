// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// File Name: time__sleep_ms.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Delay function in milliseconds for the Aixt PC port. 
#include <unistd.h>

fn sleep_ms(tms u32) int {
  return usleep(tms * 1000)
}