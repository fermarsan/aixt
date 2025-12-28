// Project name: Blinking (object oriented)
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Arduino-Nano board
import time
import pin

// declare an instance of the Pin struct
mut ext_led := pin.Pin{ pin.d15 }	// LED on D15
ext_led.setup(pin.output)

ext_led.high()	// turn on an external LED

for {
	ext_led.low()		// turn off the on-board LED
	time.sleep_ms(500)
	ext_led.high()		// turn off the on-board LED
	time.sleep_ms(500)
}