// Project name:
// Author: Fernando M. Santa
// Date: 2026
// CLI emulator (Windows, Linux and Android-Termux) 
// Description: Project example with v.mod file and .setup folder.
//   To build it you can run from a terminal the command:
//     `aixt build blinking.v`

import time
import pin_fn as pin

pin.low(pin.x)

for _ in 1..10 {
	pin.toggle(pin.x)
	time.sleep_ms(500)
}