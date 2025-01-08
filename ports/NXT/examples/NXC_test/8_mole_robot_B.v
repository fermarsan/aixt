// avoid obstacles using a touch sensor
// differential platform with the motor B inverted
import motor
import sensor
import time


@[as_macro] const t_move = 500
@[as_macro] const t_stop = 500
@[as_macro] const t_avoid = 1500
@[as_macro] const pow = 50

fn straight(power int, time int) {
	motor.write(motor.a, power)
	motor.write(motor.b, -power)	// reverse
	time.sleep_ms(time)
}

fn spin(power int, time int) {
	motor.write(motor.a, power)
	motor.write(motor.b, power)
	time.sleep_ms(time)
}

fn stop_(time int) {
	motor.off(motor.ab)
	time.sleep_ms(time)
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