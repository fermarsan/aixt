// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart

// read function reads incoming serial data
@[as_macro]
pub fn read() u8 {
	return C.UartGetChar()
}