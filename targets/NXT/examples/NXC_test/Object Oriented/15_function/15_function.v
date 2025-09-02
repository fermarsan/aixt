import motor
import sensor
import time

const t1 = 1000
const t2 = 2000

@[inline]
fn add(x i16, y i16) i16 {
	a := 10
	return x + y
}

motor_ab.write(50)
time.sleep_ms(add(t1, t2))
motor_ab.off()