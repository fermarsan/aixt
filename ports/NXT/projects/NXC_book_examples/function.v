import motor


fn turn_around() {
	motor.reverse(b, 75)
	sleep_ms(3400)
	motor.forward(ab, 75)
}	 

motor.forward(ab, 75)
sleep_ms(1)

turn_around()
sleep_ms(2)

turn_around()
sleep_ms(1)

turn_around()
motor.off(ab)
