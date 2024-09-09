// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// File Name: setup.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: SETUP (PIC18F452)
module pin

#define pin__setup(PIN_NAME, PIN_MODE)   PIN_NAME ## _s = PIN_MODE  // pin.setup(b0_s, out);  -->  b0_s = out; --> TRISBbits.RB0 = 0;

//#fn port.setup(PORT_NAME, MODE)   PORT_NAME = MODE
//#fn pin.write(PORT_NAME,VAL)      PORT_NAME = VAL  