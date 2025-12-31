// Author: Fernando M. Santa
// Date: 2024

module uart

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn print(message string) {
	C.uart_UartPutString(message)
}
