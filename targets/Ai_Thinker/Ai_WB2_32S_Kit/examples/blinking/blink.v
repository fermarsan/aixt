// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
//
// _Date:_ 2022-2024
//
// // ## Description
// Blinking led RED functions (Ai-Thinker_Ai-WB2-32S-Kit)

import time {sleep_ms}
import pin

pin.setup(1, pin.output)

for {
	pin.high(17)
	time.sleep_ms(250)
	pin.low(17)
	time.sleep_ms(250)
}
