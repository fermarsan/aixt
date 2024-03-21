import motor
import sensor

sensor.set(i1, touch)
motor.forward(ac, 75)
for sensor.read(s1) == 0 {}
motor.off(ac)