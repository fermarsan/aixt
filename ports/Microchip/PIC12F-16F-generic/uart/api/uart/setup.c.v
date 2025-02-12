// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F88x port)
module uart

@[as_macro]
pub fn setup(baudrate u32) { 
    // int16_t n = (uint8_t)(_XTAL_FREQ / (16 * baudrate)) - 1;  
    // if (n < 0)  n = 0; 
    // if (n > 255) {  // low speed
    //     n = (uint8_t)(_XTAL_FREQ / (64 * baudrate)) - 1;
    //     if (n > 255) n = 255;
    //     TXSTAbits.BRGH = 0;   // low speed
    // } else {    // high speed
    //     TXSTAbits.BRGH = 1;   // high speed
    // }
    // SPBRG = n;

    C.SPBRG = u8(C._XTAL_FREQ / (32 * baudrate)) - 1;  
    C.TXSTAbits.BRGH = 0;   // low speed

    C.TXSTAbits.SYNC = 0;   // Asyncronous
    C.TXSTAbits.TXEN = 1;   // Tx enabled
    C.TXSTAbits.TX9 = 0;    // 8 bits

    C.RCSTAbits.RC9 = 0;    // 8 bits
    C.RCSTAbits.CREN = 1;   // Rx enabled

    C.RCSTAbits.SPEN  = 1;  // serial port enabled
}