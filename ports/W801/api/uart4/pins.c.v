// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart4

// pins function sets the tx and tx pins for the uart
@[inline]
pub fn pins(tx_pin int, rx_pin int) {
	C.SERIAL4_PINS(tx_pin, rx_pin)
}