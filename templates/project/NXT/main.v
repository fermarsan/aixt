// Project name:
// Author: 
// Date: 
// NXT Intelligent Brick

import time 
import motor
import sensor

for {
	motor.write(motor.ab, 50)
	time.sleep(2)
	motor.off(motor.ab)
}