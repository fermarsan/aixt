// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions
//              (PIC16F676)
module main

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define _XTAL_FREQ 4000000

#pragma config FOSC = INTRCIO   
#pragma config WDTE = OFF      
#pragma config PWRTE = ON  
#pragma config MCLRE = OFF      
#pragma config BOREN = OFF     
#pragma config CP = OFF         
#pragma config CPD = OFF 