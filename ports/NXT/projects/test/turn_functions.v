
import motor

fn spin(left_m i16, right_m i16, power i16) {
	motor.forward(left_m, power)
	motor.reverse(right_m, power)
}

spin(a, b, 75)
sleep_ms(1000)
motor.off(ab)