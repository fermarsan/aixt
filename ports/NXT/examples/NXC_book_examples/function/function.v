import motor
import time


fn turn_around() {
	motor.write(motor.b, -75)
	time.sleep_ms(3400)
	motor.write(motor.ab, 75)
}	 

motor.write(motor.ab, 75)
time.sleep_ms(1)

turn_around()
time.sleep_ms(2)

turn_around()
time.sleep_ms(1)

turn_around()
motor.off(motor.ab)
