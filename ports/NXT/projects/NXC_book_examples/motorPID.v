import motor

const (
	p = 50
	i = 50
	d = 50
)

motor.rotate_pid(a, 100, 180, p, i, d)
sleep_ms(3000)