
import motor_fn as motor
import time

fn spin(left_m u8, right_m u8, power i8) {
	motor.write(left_m, power)
	motor.write(right_m, -power)
}

spin(motor.a, motor.b, 75)
time.sleep_ms(1000)
motor.off(motor.ab)