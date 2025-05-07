// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART functions
//              (PIC16F family)

module uart

@[as_macro]
pub fn read() u8 {
	for C.RCIF == 0 {} // wait for data receive
	if C.OERR { // if there is overrun error
		C.CREN = 0 // clear overrun error bit
		C.CREN = 1
	}
	return C.RCREG // read from USART receive data register
}
