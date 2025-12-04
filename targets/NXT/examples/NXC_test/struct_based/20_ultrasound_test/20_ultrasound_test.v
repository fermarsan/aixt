import sensor { Sensor }
import lcd
import time

mut echo_sensor := Sensor.new(sensor.s2)
echo_sensor.as_ultrasonic()

for {
    lcd.clear()
    lcd.write_num(60, lcd.line_1, echo_sensor.read())
    time.sleep_ms(500)
}
