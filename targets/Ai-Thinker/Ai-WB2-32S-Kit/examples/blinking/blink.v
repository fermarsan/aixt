// Project name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: Blinking led RED functions (Ai-Thinker_Ai-WB2-32S-Kit)

import time {sleep_ms}
import pin

pin.setup(1, pin.output)

for {
	pin.high(17)
	time.sleep_ms(250)
	pin.low(17)
	time.sleep_ms(250)
}