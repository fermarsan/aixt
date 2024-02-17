# define THRESHOLD 40

set_sensor_light(in_3)
forward(motors_ac, 75)

for {
	if sensor(in_3) > THRESHOLD {
		reverse(motor_c, 75)
		sleep(100)
		for !(sensor(in_3) <= THRESHOLD) {}
		forward(motors_ac, 75)
	} 
}