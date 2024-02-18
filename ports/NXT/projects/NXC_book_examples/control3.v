const threshold = 40

set_sensor_light(in_3)
forward(motors_ac, 75)

for {
	if sensor(in_3) > threshold {
		reverse(motor_c, 75)
		sleep(100)
		for !(sensor(in_3) <= threshold) {}
		forward(motors_ac, 75)
	} 
}