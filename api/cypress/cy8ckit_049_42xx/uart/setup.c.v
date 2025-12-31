// Author: Fernando M. Santa
// Date: 2024

module uart

// setup function sets the data rate in bits per second (baud) for serial data transmission
@[as_macro]
pub fn setup() {
	C.uart_Start()
}
