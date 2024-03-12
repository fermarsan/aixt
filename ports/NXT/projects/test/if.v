import motor

const fwd = true

if fwd {
	motor.forward(ab, 60)
	sleep_ms(1000)
} else if ! fwd {
	motor.reverse(ab, 60)
	sleep_ms(1000)
}
