// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Authors:_ Fernando M. Santa
//
// _Date:_ 2025
//
// ## Description
// Builtin LEDs
module leds

import pin

// write a integer value to the builtin LEDs
pub fn write(value u8) {
	mask := u8(0b00000001)
	for n in 0..6 {
		pin.write( led_array[n], ~( value & (mask << n) ) >> n)
	}
}
