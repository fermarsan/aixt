
// Project name:
// Author: 
// Date: 
// Arduino Uno board

import time
import disp7seg
import pin
import adc
import pwm


disp7seg.setup()
pin.setup(pin.d13, pin.output)



for {
 value := adc.read(adc.ch5)
  led_brightness := u8(value/4)
  pwm.write(pin.d13, led_brightness)

  disp7seg.precision(0)
  disp7seg.write(led_brightness)
  time.sleep_ms(100)
}


