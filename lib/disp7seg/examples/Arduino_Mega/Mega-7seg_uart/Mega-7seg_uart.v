// Project name:
// Author: 
// Date: 
// Arduino Uno board

import time
import disp7seg
import adc
import uart

disp7seg.setup()
uart.setup(9600)

mut cont := 0

for {
	analog := adc.read(adc.ch5)
	uart.println('ADC channel 0: ${analog}')
	if  analog>= 200 && analog<= 250
	{
	time.sleep_ms(1000)
	disp7seg.write(cont)
	cont++
	time.sleep_ms(500)



	if cont == 17 {
            disp7seg.digit(1, 7)
            disp7seg.digit(4, 3)
		    disp7seg.decimal_point(2, true);
			time.sleep_ms(2000)
			disp7seg.blank(true)
			time.sleep_ms(5000)
			disp7seg.blank(false)
			disp7seg.leading_zeros(true)
        } 
	}
}
