// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART module (Arduino Nano - ATmega328P port)
module uart1

#include "uart1.c"

fn C.SERIAL1_PINS(tx_pin any, rx_pin any)

// pins function sets the tx and tx pins for the uart
@[inline]
pub fn pins(tx_pin int, rx_pin int) {
	C.SERIAL1_PINS(tx_pin, rx_pin)
}
