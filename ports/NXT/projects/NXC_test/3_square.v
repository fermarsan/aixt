// "Draw" an square with a differential
// platform (motors A and B) 

const (
	t_fwd = 3000
	t_turn = 500
)

for {
	forward(motors_ab, 50)	// Aixt-style functions
	sleep(t_fwd)
	reverse(motor_a, 50)			
	sleep(t_turn)
}