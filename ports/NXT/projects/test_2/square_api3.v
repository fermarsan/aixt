

#define	t_fwd	1
#define	t_turn	500

for {
	motor.forward(mt_ab, 50)
	sleep(t_fwd)
	motor.off(mt_a)
	sleep_ms(t_turn)
}

