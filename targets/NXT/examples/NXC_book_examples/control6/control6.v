import motor
import sensor { Sensor }
import time

const near = 15

mut my_sensor := Sensor.new(sensor.s4)
my_sensor.as_lowspeed(true)

for {
	motor_ac.write(50)
	for my_sensor.read_us() > near {}
	motor_ac.off()
	motor_c.write(-100)
	time.sleep_ms(800)
}
