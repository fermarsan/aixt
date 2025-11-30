// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: uart3 module (Arduino Nano - ATmega328P port)
module uart3

#include "uart3.c"

fn C.SERIAL3_PINS(tx int, rx int)

// pins function sets the tx and tx pins for the uart3
@[inline]
pub fn pins(tx_pin int, rx_pin int) {
	C.SERIAL3_PINS(tx_pin, rx_pin)
}