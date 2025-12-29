import sensor { Sensor }
import lcd
import time


mut light_s := Sensor.new(sensor.s1)
light_s.as_light(true)

for {
    lcd.clear()
    lcd.write_num(60, lcd.line_1, light_s.read())
    time.sleep_ms(500)
}
