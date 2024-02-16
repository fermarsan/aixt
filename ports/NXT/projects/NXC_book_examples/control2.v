const (
	move_time 
	turn_time
    total_time
)

total_time = 0

for total_time < 20000 {
	move_time = random(1000)
	turn_time = random(1000)
	forward(motor_ac, 75)
	sleep(move_time)
	on_rev(motor_c, 75)
	sleep(turn_time)
	total_time += move_time
	total_time += turn_time
 }

 Off(motor_ac)


