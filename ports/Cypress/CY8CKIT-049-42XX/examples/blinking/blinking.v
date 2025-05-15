// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera
// Date: 2022-2024
// License: MIT
//
// // Description: example blinking Led (CY8CKIT-049-42XX)

import time {sleep_ms}
import pin

pin.setup(LED, output)

for {
	pin.high(LED)
	time.sleep_ms(1000)
	pin.low(LED)
	time.sleep_ms(1000)
}