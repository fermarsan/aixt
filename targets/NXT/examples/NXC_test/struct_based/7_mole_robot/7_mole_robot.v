// avoid obstacles using a touch sensor
// differential platform with the motor B inverted
import motor
import sensor { Sensor }
import time


const t_move = 500
const t_stop = 500
const t_avoid = 1500
const pow = 50

fn straight(power i8, tim u32) {
	motor_a.write(power)
	motor_b.write(-power)	// reverse
	time.sleep_ms(tim)
}

fn spin(power i8, tim u32) {
	motor_a.write(power)
	motor_b.write(power)
	time.sleep_ms(tim)
}

fn stop_(tim u32) {
	motor_ab.off()
	time.sleep_ms(tim)
}

mut touch := Sensor.new(sensor.s3)
touch.setup(sensor.touch)

for {
	straight(pow, t_move)
	if touch.read() == 1 { // if touch
		stop_(t_stop)
		straight(-pow, t_avoid) // reverse
		spin(pow, t_avoid)
	}
}