// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: uart5 module (Arduino Nano - ATmega328P port)
module uart5

#include "uart5.c"

fn C.SERIAL5_PINS(tx int, rx int)

// pins function sets the tx and tx pins for the uart5
@[inline]
pub fn pins(tx_pin int, rx_pin int) {
	C.SERIAL5_PINS(tx_pin, rx_pin)
}