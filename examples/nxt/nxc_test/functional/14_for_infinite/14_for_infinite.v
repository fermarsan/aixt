import motor_fn as motor
import time

for {
	motor.write(motor.ab, 75)
	time.sleep_ms(1000)
	motor.write(motor.a, -50)
	time.sleep_ms(1000)
	motor.off(motor.a)
	time.sleep_ms(500)
}
