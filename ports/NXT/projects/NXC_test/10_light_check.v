import sensor
import lcd

sensor.set_light(i1)
value := 0

for {
	lcd.clear()
	value = sensor.read(i1)
	lcd.print(1, 1, 'S1 = ')
	lcd.print_num(6, 1, value)
	sleep(1)
}