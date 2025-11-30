// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F family)
module uart

// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART functions
//              (PIC16F family)

@[as_macro]
pub fn any() bool {
	return C.RCIF == 1
}

@[as_macro]
pub fn print(msg string) {
	for ch in msg {
		write(u8(ch))
	}
}

@[as_macro]
pub fn println(msg string) {
	print(msg)
	write(`\n`)
	write(`\r`)
}


// @[as_macro]
pub fn read() u8 {
	for C.RCIF == 0 {} // wait for data receive
	if C.OERR == 1 { // if there is overrun error
		C.CREN = 0 // clear overrun error bit
		C.CREN = 1
	}
	return u8(C.RCREG) // read from USART receive data register
}

@[as_macro]
pub fn setup(baudrate u32) {
	mut x := u16((u32(C._XTAL_FREQ) / 16) / baudrate) - 1 // X = (FOSC / (16 * BaudRate)) – 1
	mut rem := (u32(C._XTAL_FREQ) / 16) % baudrate
	if rem >= (baudrate / 2) { // rem >= (baudrate * 16) / 2  "for rounding x using integer operations"
		x++
	}

	if x < 0 {
		x = 0
	}

	if x > 255 { // low speed
		x = u16((u32(C._XTAL_FREQ) / 64) / baudrate) - 1 // X = (FOSC / (64 * BaudRate)) – 1
		rem = (u32(C._XTAL_FREQ) / 64) % baudrate
		if rem >= (baudrate / 2) { // rem >= (baudrate * 64) / 2  "for rounding x using integer operations"
			x++
		}
		if x > 255 {
			x = 255
		}
		C.BRGH = 0 // low speed
	} else { // high speed
		C.BRGH = 1 // high speed
	}

	C.SPBRG = u8(x)

	C.SYNC = 0 // Asyncronous
	C.TX9 = 0 // 8 bits
	C.TXEN = 1 // Tx enabled

	C.SPEN = 1 // serial port enabled
	C.RX9 = 0 // 8 bits
	C.CREN = 1 // continuos Rx enabled
}


@[as_macro]
pub fn write(ch u8) {
	for C.TXIF == 0 {} // for C.TRMT == 0 {} // wait until tx buffer is empty
	C.TXREG = ch
}