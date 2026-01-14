// on motors A and B forward

import motor { Motor }
import time

const t_on = 1000
mut both := Motor.new(motor.ab)	// Motors A and B as "both"

both.write(50)
time.sleep_ms(t_on)	
both.off()