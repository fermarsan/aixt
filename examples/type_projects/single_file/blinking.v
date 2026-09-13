// Single file project
// Author: Fernando M. Santa
// Date: 2026
// Description: Single file project example (for the emulator).
//   To build it you have to run from a terminal the command:
//     `aixt build -t emu blinking.v`
//   or
//     `aixt build -t emulator blinking.v`

import time
import pin_fn as pin

pin.low(pin.x)

for _ in 1..10 {
	pin.toggle(pin.x)
	time.sleep_ms(500)
}