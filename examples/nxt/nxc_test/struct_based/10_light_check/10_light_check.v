import sensor { Sensor }
import lcd
import time


mut light_s := Sensor.new(sensor.s1)
light_s.setup(sensor.light, true)

for {
	lcd.clear()
	value := light_s.read()
	lcd.move_to(1, 1)
	lcd.print('S1 = ${value}')
	time.sleep(1)
}