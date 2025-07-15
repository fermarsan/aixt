// Project name:
// Author: 
// Date: 
// Arduino Uno board
import time
import pin
import lcd
import uart
import adc


lcd.pins(11, 10, 5, 4, 3, 2)
lcd.setup(16, 2)
uart.setup(9600)

mut cont := 0
    
lcd.set_cursor(2,0)
lcd.println(" ADC Value")

for {
	time.sleep_ms(1000)
	analog := adc.read(adc.ch5)
	uart.println('ADC channel 0: ${analog}')
	lcd.set_cursor(5,1)
	lcd.print(analog)

	if  analog>= 200 && analog<= 250 {
		lcd.clear()	
		time.sleep_ms(1000)
		lcd.set_cursor(5,1)
		lcd.print(cont)
		cont++
		time.sleep_ms(1000)
		lcd.scroll_left()
	}
	if cont== 10 {
		time.sleep_ms(1000)
		lcd.clear()
		time.sleep_ms(1000)
		lcd.home()
		lcd.println("finish")
		for  i := 0; i < 6; i++ {
			lcd.blink()
			time.sleep_ms(1000)
			lcd.set_cursor(i,0)
			time.sleep_ms(2000)
			lcd.no_blink()
		}
		break
	}
}

