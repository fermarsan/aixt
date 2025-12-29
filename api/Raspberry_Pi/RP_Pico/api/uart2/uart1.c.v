// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// UART module (Arduino Nano - ATmega328P port)
module uart2

#include "uart2.c"

fn C.SERIAL2_PINS(tx_pin any, rx_pin any)

// pins function sets the tx and tx pins for the uart
@[inline]
pub fn pins(tx_pin int, rx_pin int) {
	C.SERIAL2_PINS(tx_pin, rx_pin)
}
