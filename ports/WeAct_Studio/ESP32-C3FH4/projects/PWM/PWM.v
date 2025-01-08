import time { time_ms }
import pin
import pwm 

__global(
	val1 = 0 
	val2 = 0 
	val3 = 0
)

pin.setup(1, pin.output)put)
pin.setup(4, pin.output)put)
pin.setup(10, pin.output)put)

for{ 
	pwm.write(1, val1)
	pwm.write(4, val2)
	pwm.write(10, val3)
	time.sleep_ms(500)
	val1=val1+50
	val2=val2+25
	val3=val3+25
	if val1==400 { 
		val1=0 
	}

	if val2 == 150 { 
		val2 = 0
	}

	if val3 == 100 { 
		val3 = 0 
	}
}