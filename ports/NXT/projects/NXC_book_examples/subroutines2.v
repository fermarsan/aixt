@[inline] fn turn_around()
{
	reverse(motor_c, 75) 
	sleep(900)
	forward(motors_ac, 75)
}

forward(motors_ac, 75)
sleep(1000)
turn_around()
sleep(2000)
turn_around()
sleep(1000)
turn_around()
off(motors_ac)