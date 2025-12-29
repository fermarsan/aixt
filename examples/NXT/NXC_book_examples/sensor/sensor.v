import motor_fn as motor
import sensor { Sensor }


mut touch := Sensor.new(sensor.s1)
touch.setup(sensor.touch)

motor_ac.write(75)

for touch.read() == 0 {}// wait while do not touch

motor_ac.off()
