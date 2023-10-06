// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Javier Leon, Camilo Lucas and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Microseconds delay function
//              (CY8CKIT-145-40XX)
#include <libpic30.h>

#define sleep_us(TIME)    CyDelayUs(TIME)