// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// uart4 module (Arduino Nano - ATmega328P port)
module uart4

#include "uart4.c"

fn C.SERIAL4_PINS(tx int, rx int)

// pins function sets the tx and tx pins for the uart4
@[inline]
pub fn pins(tx_pin int, rx_pin int) {
	C.SERIAL4_PINS(tx_pin, rx_pin)
}