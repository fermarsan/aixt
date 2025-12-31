// Author: Fernando M. Santa
// Date: 2024

module uart

// write function sends a single byte to the serial port
@[as_macro]
pub fn write(character u8) {
	C.uart_UartPutChar(character)
}
