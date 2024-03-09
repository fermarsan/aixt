import motor

motor.forward(ac, 75)
sleep_ms(800)
motor.reverse(c, 75)
sleep_ms(360)
motor.off(ac)