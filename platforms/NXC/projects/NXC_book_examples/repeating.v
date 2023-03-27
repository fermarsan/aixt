const (
	move_time = 1000
	turn_time = 500
)



for n in 1 .. 4 {
	on_fwd(out_ac, 75)
	wait(move_time)
	on_rev(out_c, 75)
	wait(turn_time)
}

off(out_ac)