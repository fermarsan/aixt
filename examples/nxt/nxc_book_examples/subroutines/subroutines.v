import motor_fn as motor
import time

fn turn_around(pwr int) {
    motor.write(motor.c, -pwr)
    time.sleep_ms(900)
    motor.write(motor.ac, pwr)
}

motor.write(motor.ac, 75)
time.sleep_ms(1000)
turn_around(75)
time.sleep_ms(2000)
turn_around(75)
time.sleep_ms(1000)
turn_around(75)
motor.off(motor.ac)