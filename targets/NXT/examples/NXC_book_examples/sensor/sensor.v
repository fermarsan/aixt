import motor
import sensor

sensor.setup(sensor.s1, sensor.touch)
motor.write(motor.ac, 75)
for sensor.read(sensor.s1) == 0 {}
motor.off(motor.ac)