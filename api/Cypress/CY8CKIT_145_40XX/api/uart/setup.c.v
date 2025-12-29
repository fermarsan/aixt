// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
// License: MIT
module uart

// setup function sets the data rate in bits per second (baud) for serial data transmission
@[as_macro]
pub fn setup() {
	C.uart_Start()
}