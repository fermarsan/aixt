// Project name:
// Author: 
// Date: 
// Arduino Uno board

import time
import disp7seg
import adc



disp7seg.setup()



for {
 val := adc.read(adc.ch5)
  voltage := f64(f64(5.00)*val)/1024
 

  disp7seg.precision(2)
  disp7seg.value_double(voltage)
  time.sleep_ms(100)
}

