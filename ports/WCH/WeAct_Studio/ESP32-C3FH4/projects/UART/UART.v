import pin
import uart

__global( 
	button=0
 )

 pin.setup(4, pin.output)
 uart.setup(9600)

 for {

	if pin.read(4) == 1
	{
		button=button+1
		uart.print(button)
	}
 }

