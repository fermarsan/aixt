// Project name: Blinking (object oriented)
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Nano board
import time
import pin_oop as pin

// mut ext_led := pin.Pin{ pin.d15 }


// ext_led.high()	// turn on an external LED

for {
	pin.led0.low()		// turn off the on-board LED
	time.sleep_ms(500)
	pin.led0.high()		// turn off the on-board LED
	time.sleep_ms(500)
}