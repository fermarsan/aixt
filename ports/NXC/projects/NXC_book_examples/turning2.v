const (
	move_time = 1000
	turn_time = 360
)

on_forward(out_ac, 75)
sleep(move_time)
on_reverse(out_c, 75)
sleep(turn_time)
off(out_ac)