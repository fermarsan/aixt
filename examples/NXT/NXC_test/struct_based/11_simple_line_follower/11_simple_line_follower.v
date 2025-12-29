// Project name: Line follower
// Author: Fernando M. Santa
// Date: 2024-2025

import motor
import sensor { Sensor }
import time

mut line_sensor := Sensor.new(sensor.s4)
line_sensor.as_light(true)

time.sleep(2)	// starting delay

for {
	motor_ab.write(75)	// starts on the black line
	time.sleep_ms(100)

	if line_sensor.read() <= 30 {	// black line
		motor_a.off()	// off
		time.sleep_ms(300)
		motor_a.write(-75)	// reverse
		time.sleep_ms(500)	
	}
}
