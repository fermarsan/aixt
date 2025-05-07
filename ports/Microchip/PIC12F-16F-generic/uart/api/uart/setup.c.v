// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Pin management functions
//              (PIC16F family)
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

	mut x := i16(0)
	x = u8(u32(C._XTAL_FREQ) / (baudrate << 4)) - 1 // X = (FOSC / (16 * BaudRate)) – 1
	if x < 0 {
		x = 0
	}
	if x > 255 { // low speed
		x = u8(u32(C._XTAL_FREQ) / (baudrate << 6)) - 1 // X = (FOSC / (64 * BaudRate)) – 1
		if x > 255 {
			x = 255
		}
		C.BRGH = 0 // low speed
	} else { // high speed
		C.BRGH = 1 // high speed
	}
	C.SPBRG = u8(x)
	// C.SPBRG = u8(C._XTAL_FREQ / (32 * baudrate)) - 1
	C.BRGH = 0 // low speed

	C.SYNC = 0 // Asyncronous
	C.TXEN = 1 // Tx enabled
	C.TX9 = 0 // 8 bits

	C.RX9 = 0 // 8 bits
	C.CREN = 1 // Rx enabled
	C.SPEN = 1 // serial port enabled
}
