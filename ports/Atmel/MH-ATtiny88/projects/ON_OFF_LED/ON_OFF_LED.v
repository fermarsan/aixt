import time { sleep_ms }  // import the time module from the API
import pin				  // import the pin module from the API

pin.setup(1, pin.output)  // configures pin number 1 as output 

for {                     //main loop of the code 
	pin.high(1)			  //pin high
	sleep_ms(500)		  //delay in seconds 
	pin.low(1)			  //pin low
	sleep_ms(500)		  //delay in seconds
}
