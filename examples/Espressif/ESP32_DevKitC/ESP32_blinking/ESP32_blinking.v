// Project name: Blinking
// Author: Fernando M. Santa
// Date: 19/09/2024
// ESP32-DevKitC board

import time
import pin

pin.setup(pin.gpio2, pin.output)

for {
	pin.high(pin.gpio2)
	time.sleep_ms(500)
	pin.low(pin.gpio2)
	time.sleep_ms(500)
}
