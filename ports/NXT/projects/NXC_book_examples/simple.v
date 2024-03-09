import motor

motor.forward(a, 75)
motor.forward(b, 50)
sleep_ms(4000)
motor.reverse(ab, 75)
sleep_ms(4000)
motor.off(ab)