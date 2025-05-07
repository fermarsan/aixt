// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART functions
//              (PIC16F family)
module uart

@[as_macro]
pub fn print(msg string) {
	for ch in msg {
		write(ch)
	}
}
