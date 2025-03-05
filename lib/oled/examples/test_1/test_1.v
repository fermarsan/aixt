// Project name:
// Author: 
// Date: 
// Raspberry Pi Pico board

import oled
import uart
import time

uart.setup(115200)

for{
	if oled.setup(C.SSD1306_SWITCHSPVCC, 0x3C) {
		uart.println('SSD1306 allocation failed') 	
	}
	time.sleep_ms(2000)
	oled.clear()
	oled.size(1)
	oled.color(C.WHITE)
	oled.setcursor(0,0)
	oled.println('HELLO WORLD')
} 

