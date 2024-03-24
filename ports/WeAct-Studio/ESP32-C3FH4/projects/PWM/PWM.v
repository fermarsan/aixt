import time { sleep_ms }
import pin
import pwm

__global (
  val1 = 0
  val2 = 0 
  val3 = 0 
)

pin.setup(3, pin.output)
pin.setup(4, pin.output)
pin.setup(6, pin.output)

for {
    pwm.write(3, val1)
	pwm.write(4, val2)
	pwm.write(6, val3)
    sleep_ms(500)
    val1=val1+20
	val2=val2+15
	val3=val3+15
    if val1==500 {
		  val1=0  
    }

	if val2 == 400 {
		val2 = 0
	}

	if val3 == 250 {
		val3 = 0
	}
} 