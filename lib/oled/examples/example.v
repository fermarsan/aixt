import wire.h    
import Adafruit.GFX.h
import Adafruit_SSD1306.h


import oled
import uart
import time
import pin 


uart.setup(115200)

for{

 if oled.setup(SSD1306_SWITCHSPVCC, 0x3C) {
	uart.println('SSD1306 allocation failed') 	
 }

 time.delay(2000)
 oled.clear()
 oled.size(1)
 oled.color(WHITE)
 oled.setcursor(0,0)
 oled.println('HELLO WORLD')
 

} 