// avoid obstacles using a touch sensor
// differential platform with the motor B inverted

const (
	t_move = 500
	t_stop = 500
	t_avoid = 1500
	pow = 50
)

fn straight(power int, time int) {
	on_forward(out_a, power)
	on_reverse(out_b, power)
	sleep(time)
}

fn spin(power int, time int) {
	on_forward(out_a, power)
	on_forward(out_b, power)
	sleep(time)
}

fn _stop(time int) { off(out_ab); sleep(time) }

set_sensor_touch(in_3)

// a := 0

for {
	straight(pow, t_move)

	// a = sensor(s3)
	if sensor(s3) == 1{			// if touch
		_stop(t_stop)
		straight(-pow, t_avoid)	//reverse
		spin(pow, t_avoid)
	}
}
