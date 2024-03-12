// avoid obstacles using a touch sensor
// differential platform with the motor B inverted
import motor
import sensor

const t_move = 500
const t_stop = 500
const t_avoid = 1500
const pow = 50

fn straight(power int, time int) {
	motor.forward(a, power)
	motor.reverse(b, power)
	sleep_ms(time)
}

fn spin(power int, time int) {
	motor.forward(a, power)
	motor.forward(b, power)
	sleep_ms(time)
}

fn _stop(time int) {
	motor.off(ab)
	sleep_ms(time)
}

sensor.set_touch(i3)

a := 0

for {
	straight(pow, t_move)

	a = sensor(s3)
	if a == 1 { // if touch
		_stop(t_stop)
		straight(-pow, t_avoid) // reverse
		spin(pow, t_avoid)
	}
}
