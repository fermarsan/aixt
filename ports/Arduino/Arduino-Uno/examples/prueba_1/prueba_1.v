// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Uno board
import time
import pin

for {
	pin.high(led0)
	time.sleep_ms(100)
	pin.low(led0)
	time.sleep_ms(200)
}