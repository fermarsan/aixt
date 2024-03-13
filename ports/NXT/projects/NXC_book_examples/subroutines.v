import motor

fn turn_around(pwr int) {
    motor.reverse(c, pwr)
    sleep_ms(900)
    motor.forward(ac, pwr)
}

motor.forward(ac, 75)
sleep_ms(1000)
turn_around(75)
sleep_ms(2000)
turn_around(75)
sleep_ms(1000)
turn_around(75)
motor.off(ac)
