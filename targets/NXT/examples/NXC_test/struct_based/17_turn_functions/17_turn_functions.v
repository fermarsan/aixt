import motor { Motor }
import time

fn spin(left_m Motor, right_m Motor, power i8) {
	left_m.write(power)
	right_m.write(-power)
}

spin(motor_a, motor_b, 75)
time.sleep_ms(1000)
motor_ab.off()