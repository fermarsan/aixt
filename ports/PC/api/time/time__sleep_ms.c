// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: time__sleep_ms.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Delay function in milliseconds for the Aixt PC port. 
#include <unistd.h>

int sleep_ms(unsigned int tms) {
  return usleep(tms * 1000);
}