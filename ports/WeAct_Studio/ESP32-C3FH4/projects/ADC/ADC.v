import pin 
import adc
import pwm
import time

__global ( 
	volumen=0 
	)
for { 
	volumen=adc.read(3)
	pwm.write(7,volumen)
}
