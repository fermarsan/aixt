
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
  brillo_led := u8(value/4)
  pwm.write(pin.d13, brillo_led)

  disp7seg.precision(0)
  disp7seg.write(brillo_led)
  time.sleep_ms(100)
}


