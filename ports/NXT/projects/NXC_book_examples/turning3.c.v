#define	move_time 1000
#define	turn_time 360

forward(motors_ac, 75)
sleep(move_time)
reverse(motor_c, 75)
sleep(turn_time)
off(motors_ac)