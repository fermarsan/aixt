import sensor_fn as sensor
import lcd
import time

sensor.as_ultrasonic(sensor.s2)

for {
    lcd.clear()
    lcd.write_num(60, lcd.line_1, sensor.read(sensor.s2))
    time.sleep_ms(500)
}
