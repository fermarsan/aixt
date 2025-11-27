// Project name: On-board LED blinking
// Author:	Fernando M. Santa & Santiago Farfán
// Date:	09/05/2025
// STM32G431Core board
import time
import pwm

const led_pwm = 8 // PA8

__global duty = u8(0)

for {
	pwm.write(led_pwm, duty)
	duty++
	time.sleep_ms(10)
}
