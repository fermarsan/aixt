import sensor
import lcd

sensor.set_light(i1)
value := 0

for {
	lcd.clear()
	value = sensor.read(i1)
	lcd.print('S1 = ')
	lcd.print_num(value)
	sleep(1)
}