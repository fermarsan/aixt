// Project name: Blinking (object oriented)
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Nano board
import time
import pin { led0 }

mut ext_led := pin.new_pin(pin.d15, pin.output)

led0.low()		// turn off the on-board LED
ext_led.high()	// turn on an external LED

for {
	led0.toggle()		// toggle both
	ext_led.toggle()
	time.sleep_ms(500)
}