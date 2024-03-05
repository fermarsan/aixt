// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin.c
// Author: Andrés Felipe Fajardo and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC18F2550)

#include <xc.h>

#define out 0   // pin mode (direction)
#define in  1

#define pin_setup(PIN_NAME, MODE)     PIN_NAME = MODE  // pin_setup(b0_s, out);  -->  b0_s = out; --> TRISBbits.RB0 = 0;
#define port_setup(PORT_NAME, MODE)   PORT_NAME = MODE // TRISB = MODE  port_setup(b_s,)
#define port_write(PORT_NAME,VAL)     PORT_NAME = VAL  // LATB = VAL   
#define port_read(PORT_NAME)          PORT_NAME        // PORTB
#define pin_high(PIN_NAME)            PIN_NAME = 1          // LATBbits.LB0 = 1
#define pin_low(PIN_NAME)             PIN_NAME = 0          // LATBbits.LB0 = 0
#define pin_write(PIN_NAME,VAL)       PIN_NAME = VAL        // LATBbits.LB0 = 0
#define pin_read(PIN_NAME)            PIN_NAME              // PORTBbits.RB0 