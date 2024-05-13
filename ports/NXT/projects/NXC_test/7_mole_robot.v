// avoid obstacles using a touch sensor
// differential platform with the motor B inverted
import motor
import sensor

const (
	t_move = 500
	t_stop = 500
	t_avoid = 1500
	pow = 50
)

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

fn stop_(time int) {
	motor.off(ab)
	sleep_ms(time)
}

sensor.set_touch(i3)

for {
	straight(pow, t_move)
	if sensor.read(i3) == 1 { // if touch
		stop_(t_stop)
		straight(-pow, t_avoid) // reverse
		spin(pow, t_avoid)
	}
}
