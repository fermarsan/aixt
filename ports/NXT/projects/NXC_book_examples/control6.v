#define NEAR 15

set_sensor_lowspeed(in_4)

for {
	forward(motor_ac,50)
	for sensor_us(in_4)>NEAR {}
	off(motor_ac)
	reverse(motor_c,100)
	sleep(800)
}