// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
// License: MIT
module uart

// write function sends a single byte to the serial port
@[as_macro]
pub fn write(character u8) {  
	C.uart_UartPutChar(character)
}