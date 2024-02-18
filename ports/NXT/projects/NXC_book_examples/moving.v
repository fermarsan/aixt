#define	turn_time 360
const (move_time )

move_time = 200

for n in 1..50 {
	forward(motors_ac, 75)
	sleep(move_time)
	reverse(motor_c, 75)
	sleep(turn_time)
    move_time += 200
}
off(motors_ac)