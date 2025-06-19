// Project name:
// Author: 
// Date: 
// Arduino Mega board

import time
import lcd


lcd.pins(11,10,5,4,3,2)
lcd.setup(16,2)


mut cont := 0

for {
	lcd.set_cursor(5,0)
	lcd.println("counter")
	lcd.set_cursor(7,2)
	lcd.print(cont)
	cont++
	time.sleep_ms(1000)
	if cont== 10 {
		time.sleep_ms(1000)
		lcd.clear()
		time.sleep_ms(1000)
		lcd.println("finish")
		time.sleep_ms(3000)
		lcd.clear()
		break
	}
}