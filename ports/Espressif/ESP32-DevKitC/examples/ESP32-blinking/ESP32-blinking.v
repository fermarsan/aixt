// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 19/09/2024
// ESP32-DevKitC board

import time
import pin

pin.setup(2, output)

for {
	pin.high(2)
	time.sleep_ms(500)
	pin.low(2)
	time.sleep_ms(500)
}
