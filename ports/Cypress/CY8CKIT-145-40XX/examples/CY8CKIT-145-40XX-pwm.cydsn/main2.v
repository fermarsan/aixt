import time {sleep_ms}
import pwm

mut val := 0

//pin.setup(17, pin.output)

for {
    pwm.write(pwm_1, val)
    sleep_ms(1000)
    val=val+2000
    if val==10000{
		val=0  
    }
} 