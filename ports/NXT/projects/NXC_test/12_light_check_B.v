import sensor
import lcd
import str

sensor.set_light(i1)
value := 0

for {
	lcd.clear()
	value = sensor.read(s1)
	lcd.move_to(1, 1)
	lcd.print('S1 = ' + str.from_num(value))
	sleep(1)
}