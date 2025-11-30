import sensor_fn as sensor
import lcd
import time


sensor.as_light(sensor.s1, true)

for {
	lcd.clear()
	value := sensor.read(sensor.s1)
	lcd.move_to(1, 1)
	lcd.print('S1 = ${value}')
	time.sleep(1)
}