// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
//
// _Date:_ 2022-2024
//
// // ## Description
// pwm Ouput functions (Ai-Thinker_Ai-WB2-32S-Kit)

import time {sleep_ms}
import pin
import pwm

__global val = 0

pin.setup(17, pin.output)

for {
    pwm.write(17, val)
    sleep_ms(250)
    val=val+10
    if val==250{
		val=0
    }
}
