// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F88x port)
module uart

@[as_macro]
pub fn println(msg string) {
	uart.print(msg)
	uart.write('\n')
	uart.write('\r')
}