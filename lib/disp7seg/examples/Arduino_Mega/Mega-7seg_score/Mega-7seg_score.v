// Project name:
// Author: 
// Date: 
// Arduino Uno board

import time
import disp7seg
import pin


pin.setup(pin.d12, pin.input)
pin.setup(pin.d7, pin.input)
disp7seg.setup()
mut cont := 0
mut cont_1 := 0


for {
 disp7seg.digit(1,cont )   
  disp7seg.digit(4,cont_1)
 disp7seg.decimal_point(2, true); 
   if pin.read(pin.d12) == 1 
   {
    	time.sleep_ms(500)
   disp7seg.digit(1,cont ) 
   cont++  
   }
    if  pin.read(pin.d7)== 1
   {
     	time.sleep_ms(500)
	 disp7seg.digit(4,cont_1 )   
     cont_1++        
           
        } 

		if  cont>9 || cont_1>9 {
          
			disp7seg.blank(true)
			time.sleep_ms(500)
			disp7seg.blank(false)
        } 
}

