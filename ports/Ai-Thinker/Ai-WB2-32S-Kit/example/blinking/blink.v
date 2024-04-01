// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: blink.v
// Author: Fernando Martínez Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: Blinking led RED functions (Ai-Thinker_Ai-WB2-32S-Kit)

import time {sleep_ms}
import pin

pin.setup(1, pin.out)

for {
	pin.high(17)
	sleep_ms(250)
	pin.low(17)
	sleep_ms(250)
}