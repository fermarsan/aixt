import sensor
import lcd

sensor.set_light(i1)
value := 0

for {
	lcd.clear()
	value = sensor.read(i1)
	lcd.move_to(1, 1)
	lcd.print('S1 = ${value}')
	sleep(1)
}