// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: time__sleep_us.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Delay function in microseconds for the Aixt PC port. 
#include <unistd.h>

#define sleep_us(TIME)    usleep(TIME)
