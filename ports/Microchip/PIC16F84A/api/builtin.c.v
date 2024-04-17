// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (PIC16F84A port)

module main

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define _XTAL_FREQ 4000000

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

