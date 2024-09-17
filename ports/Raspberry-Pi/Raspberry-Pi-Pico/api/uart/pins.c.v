// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart

#include "pins.h"

// pins function sets the rx and tx pins for the uart
@[inline]
pub fn pins(rx_pin int, tx_pin int) {
	C.uart__pins(rx_pin, tx_pin)
}