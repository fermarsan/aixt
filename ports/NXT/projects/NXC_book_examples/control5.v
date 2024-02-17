#define THRESHOLD 40
#define MIC SENSOR_2

set_sensor_sound(in_2)

for {
	for !(MIC > THRESHOLD) {}
	forward(motor_ac, 75)
	sleep(300)
	for !(MIC > THRESHOLD) {}
	off(motor_ac)
	sleep(300)
}