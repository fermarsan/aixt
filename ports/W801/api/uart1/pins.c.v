// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart1

// pins function sets the tx and tx pins for the uart1
@[inline]
pub fn pins(tx_pin int, rx_pin int) {
	C.SERIAL1_PINS(tx_pin, rx_pin)
}