#define threshold 40
#define mic sensor_2

set_sensor_sound(in_2)

for {
	for !(mic > threshold) {}
	forward(motors_ac, 75)
	sleep(300)
	for !(mic > threshold) {}
	off(motors_ac)
	sleep(300)
}