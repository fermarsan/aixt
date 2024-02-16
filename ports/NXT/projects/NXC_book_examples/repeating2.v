#define	move_time 1000
#define	turn_time 500


for n in 1..10 {
	for n in 1..4 {
		forward(motors_ac, 75)
		sleep(move_time)
		on_rev(motor_c, 75)
		sleep(turn_time)
	}
}
off(motors_ac)