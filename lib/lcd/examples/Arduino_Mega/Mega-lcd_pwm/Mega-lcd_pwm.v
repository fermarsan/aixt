// Project name:
// Author: 
// Date: 
// Arduino Uno board

import time
import lcd
import pin
import adc
import pwm


lcd.pins(11,10,5,4,3,2)
lcd.setup(16,2)

for {
  value := adc.read(adc.ch5)
  time.sleep_ms(100)
  lcd.home()
  lcd.println("led brightness:")
  lcd.set_cursor(11, 0) 
  lcd.print(value)
  time.sleep_ms(1000)
  lcd.clear();
  time.sleep_ms(100)
  led_brightness := u8(value/4)
  pwm.write(pin.d6, led_brightness)
  lcd.set_cursor(2, 1) 
  lcd.println("PWM:")
  lcd.set_cursor(7, 1) 
  lcd.print(led_brightness)
  time.sleep_ms(1000)
  lcd.clear()
}
  





