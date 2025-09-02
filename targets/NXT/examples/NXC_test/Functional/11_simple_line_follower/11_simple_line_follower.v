// Project name: Line follower
// Author: Fernando M. Santa
// Date: 2024-2025

import motor_fn as motor
import sensor_fn as sensor
import time


sensor.setup(sensor.s4, sensor.light)	// light sensor on input 4
//sensor.as_light(sensor.s4)			// alternative function

time.sleep(2)	// starting delay

for {
	motor.write(motor.ab, 75)	// starts on the black line
	time.sleep_ms(100)

	if sensor.read(sensor.s4) <= 30 {	// black line
		motor.off(motor.a)	// off
		time.sleep_ms(300)
		motor.write(motor.a, -75)	// reverse
		time.sleep_ms(500)	
	}
}