// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 19/09/2024
// ESP32-DevKitC board

import time
import pin

pin.setup(gpio2, output)

for {
	pin.high(gpio2)
	time.sleep_ms(500)
	pin.low(gpio2)
	time.sleep_ms(500)
}
