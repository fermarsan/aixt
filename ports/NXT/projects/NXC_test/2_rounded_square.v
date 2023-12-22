// "Draw" a rounded square with a differential
// platform (motors A and B) 

const (
	t_on = 2000
	t_turn = 500
)

forward(motors_ab, 60)	// move forward
sleep(t_on)
off(motor_a)			// off motor A to turn
sleep(t_turn)

forward(motors_ab, 60)
sleep(t_on)
off(motor_a)
sleep(t_turn)

forward(motors_ab, 60)
sleep(t_on)
off(motor_a)
sleep(t_turn)

forward(motors_ab, 60)
sleep(t_on)
off(motor_a)
sleep(t_turn)

off(motors_ab)			// stop