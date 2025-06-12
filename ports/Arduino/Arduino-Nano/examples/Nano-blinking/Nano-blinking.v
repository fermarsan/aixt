// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Nano board
import time
import pin

for {
	pin.high(led_0)
	time.sleep_ms(500)
	pin.low(led_0)
	time.sleep_ms(500)
}