// avoid obstacles using a touch sensor
// differential platform with the motor B inverted
import motor
import sensor
import time


@[as_macro] const t_move = 500
@[as_macro] const t_stop = 500
@[as_macro] const t_avoid = 1500
@[as_macro] const pow = 50

fn straight(power i8, tim u32) {
	motor_a.write(power)
	motor_b.write(-power)	// reverse
	time.sleep_ms(tim)
}

fn spin(power i8, tim u32) {
	motor_a.write(power)
	motor_b.write(power)
	time.sleep_ms(tim)
}

fn stop_(tim u32) {
	motor_ab.off()
	time.sleep_ms(tim)
}


sensor.as_touch(sensor.s3)

for {
	straight(pow, t_move)
	if sensor.read(sensor.s3) == 1 { // if touch
		stop_(t_stop)
		straight(-pow, t_avoid) // reverse
		spin(pow, t_avoid)
	}
}
