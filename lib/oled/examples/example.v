import oled
import uart
import time

uart.setup(115200)

for{
	if oled.setup(oled.ssd1306_switchspvcc, 0x3C) {		
		uart.println('SSD1306 allocation failed') 	
	}	
	time.delay(2000)
	oled.clear()
	oled.set_text_size(1)
	oled.set_text_color(oled.white)
	oled.set_cursor(0, 0)
	oled.println('HELLO WORLD')
} 