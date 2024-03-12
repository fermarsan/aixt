import motor

const turn_time = 360

move_time := 200

for n in 1..50 {
	motor.forward(ac, 75)
	sleep_ms(move_time)
	motor.reverse(c, 75)
	sleep_ms(turn_time)
    move_time += 200
}

motor.off(ac)