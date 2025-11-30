// Project name: Aixt https://github.com/fermarsan/aixt.git
// Authors: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Builtin LEDs
module leds

import pin

// setup builtin LEDs as output
pub fn setup() {
	for led in led_array {
		pin.setup(led, pin.output)
	}
}