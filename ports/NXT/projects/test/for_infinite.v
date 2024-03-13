for {
	motor.forward(ab, 75)
	sleep_ms(1000)
	motor.reverse(a, 50)
	sleep_ms(1000)
	motor.off(a)
	sleep_ms(500)
}
