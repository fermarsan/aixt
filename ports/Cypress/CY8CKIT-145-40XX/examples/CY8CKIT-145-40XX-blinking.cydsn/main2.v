import time {sleep_ms}
import pwm

//__global val = 0

//pin.setup(17, pin.output)

for {
    pwm.write(pwm1, val)
    sleep_ms(1000)
    val=val+2000
    if val==10000{
		val=0  
    }
} 