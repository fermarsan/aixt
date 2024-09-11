// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F676 port)

module pin

#define pin.high(PIN_NAME)  PIN_NAME = 1
