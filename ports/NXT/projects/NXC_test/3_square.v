// "Draw" an square with a differential platform (motors A and B) 

const (
	t_forward= 3000
	t_turn = 500
)

for {
	forward(motors_ab, 50)
	sleep(t_forward)
	reverse(motor_a, 50)			
	sleep(t_turn)
}