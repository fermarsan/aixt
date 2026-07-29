// Project name: breathing
// Author: 
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2024-2026
// ch55x boards

import time
import pin_fn as pin
import pwm_fn as pwm

pin.setup(pwm.ch1_1, pin.output)

for {
    for level in 0 .. 256 {
        pwm.write(pwm.ch1_1, level)
        time.sleep_ms(5)
    }

    for level in 0 .. 256 {
        pwm.write(pwm.ch1_1, 255 - level)
        time.sleep_ms(5)
    }

    time.sleep_ms(100)
}