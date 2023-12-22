#define	t_fwd	1000
#define	t_turn	500

for {
	forward(motors_ab)
	sleep(t_fwd)
	off(motor_a)
	sleep(t_turn)
}

