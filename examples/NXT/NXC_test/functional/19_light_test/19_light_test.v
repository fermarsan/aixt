import sensor_fn as sensor
import lcd
import time

sensor.as_light(sensor.s1, true)

for {
    lcd.clear()
    lcd.write_num(60, lcd.line_1, sensor.read(sensor.s1))
    time.sleep_ms(500)
}
