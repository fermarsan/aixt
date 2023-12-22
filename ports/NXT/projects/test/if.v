const fwd = true

if fwd {
	forward(motors_ab, 60)
	sleep(1000)
} else if ! fwd {
	reverse(motors_ab, 60)
	sleep(1000)
}
