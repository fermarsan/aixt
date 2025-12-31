// Author: Fernando M. Santa
// Date: 2024

module uart

// read function reads incoming serial data
@[as_macro]
pub fn read() u8 {
	return C.uart_UartGetChar()
}
