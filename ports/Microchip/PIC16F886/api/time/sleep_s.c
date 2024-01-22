// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_s.c
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: seconds delay function
//              (PIC16F886 port)
#include <xc.h>

#define sleep_s(TIME)    __delay_s(TIME)  // implementing by a macro for saving memory