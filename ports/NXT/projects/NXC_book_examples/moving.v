#define	turn_time 360
const (move_time )

move_time = 200

for n in 1..50 {
	forward(motor_ac, 75)
	sleep(move_time)
	on_rev(motor_c, 75)
	sleep(turn_time)
    move_time += 200
}
off(motor_ac)