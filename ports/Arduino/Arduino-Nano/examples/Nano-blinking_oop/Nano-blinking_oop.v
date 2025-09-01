// Project name: Blinking (object oriented)
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Nano board
import time
import pin_opp as pin

mut ext_led := pin.new(pin.d15, pin.output)

pin.led0.low()		// turn off the on-board LED
ext_led.high()	// turn on an external LED

for {
	pin.led0.toggle()		// toggle both
	ext_led.toggle()
	time.sleep_ms(500)
}