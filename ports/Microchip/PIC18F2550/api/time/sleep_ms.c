// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_ms.c
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Milliseconds delay function
//              (PIC18F2550)

#include <xc.h>
#define sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory
