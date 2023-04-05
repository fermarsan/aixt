// "Draw" a rounded square with a differential
// platform (motors A and B) 

const (
	t_on = 2000
	t_turn = 500
)

on_fwd(out_ab, 60)	// move forward
wait(t_on)
off(out_a)			// off motor A to turn
wait(t_turn)

on_fwd(out_ab, 60)
wait(t_on)
off(out_a)
wait(t_turn)

on_fwd(out_ab, 60)
wait(t_on)
off(out_a)
wait(t_turn)

on_fwd(out_ab, 60)
wait(t_on)
off(out_a)
wait(t_turn)

off(out_ab)			// stop