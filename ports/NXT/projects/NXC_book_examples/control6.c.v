#define near 15

set_sensor_lowspeed(in_4)

for {
	forward(motors_ac,50)
	for sensor_us(in_4) > near {}
	off(motors_ac)
	reverse(motor_c,100)
	sleep(800)
}