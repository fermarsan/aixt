import time { sleep_ms }
import pin
import pwm

__global (
  val = 0
)

pin.setup(5, pin.output)

for {
    pwm.write(5, val)
    sleep_ms(250)
    val=val+10
    if val==250 {
		  val=0  
    }
} 