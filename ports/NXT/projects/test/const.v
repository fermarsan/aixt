const (
	t_on  = 1000
	t_off = 500
)

// const t_on = 1000
// const t_off = 500
// const a = 34.67

forward(motors_ab,70)
sleep(t_on)

off(motors_ab)
sleep(t_off)

forward(motors_ab,70)
sleep(t_on)

off(motors_ab)
