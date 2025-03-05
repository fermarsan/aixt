// Project name:
// Author: 
// Date: 
// Arduino Uno board

import time
import disp7seg

disp7seg.setup()

mut cont := 0

for {
	disp7seg.write(cont)
	cont++
	time.sleep_ms(500)
}

