// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: pwm.v
// Author: Fernando Martínez Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: pwm Ouput functions (Ai-Thinker_Ai-WB2-32S-Kit)

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