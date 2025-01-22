// Project name: Power Off example
// Author: Fernando M. Santa	
// Date: 21/01/2025
// M5Stack FIRE IoT development kit

import lcd 
import button
import power
import time


power.setup()     	// Init Power module.
lcd.text_size(2)	// Set the font size.
lcd.print('After 5 seconds, the program ')	// Screen printing
lcd.println('entered light sleep\n')  		// formatted string.

time.sleep(5)
power.light_sleep(power.sec(5))  // Sleep for 5 seconds, then continue the program.

lcd.print('press ButtonA: shutdown,  use ') // Screen printing
lcd.println('power button to turn  back on')// formatted string.
                                                         
for {
    update()  // Read the press state of the key. A, B, C
    if button.was_pressed(button.a) {  // check if the A key is pressed. 
	    power.power_off()	// turn off power.
    }
}