import motor { Motor }
import time { sleep_ms }

mut both := Motor.new(motor.ac)

both.write(75)
sleep_ms(500)

both.off()
sleep_ms(1000)

both.write(75)
sleep_ms(500)

both.float()