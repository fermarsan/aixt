// on motors A and B forward

import motor
import time

const t_on = 1000

both := motor.Motor{ motor.ab }

both.write(50)
time.sleep_ms(t_on)	
both.off()