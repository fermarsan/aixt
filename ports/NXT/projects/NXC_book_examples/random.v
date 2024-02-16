const (
	move_time 
	turn_time
)

 while(true)
 {
 move_time = random(600)
 turn_time = random(400)
 forward(motor_ac, 75)
 sleep(move_time)
 on_rev(motor_a, 75)
 sleep(turn_time)
 }