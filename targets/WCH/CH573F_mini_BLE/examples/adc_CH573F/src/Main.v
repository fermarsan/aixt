import pin { setup }                         
import pwm      
import adc

pin.setup(pin.a4, pin.input) 

adc.setup(0)

value := 0

for {     
    adc.read(value)
	pwm.write(4, value)
    }
