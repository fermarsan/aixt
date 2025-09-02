
import pin  //import the module pin from API
import uart //import the module uart from API

__global(
button:=0  //defined global variable initialized to 0
        )


for {       //for loop that executes the main code

	if pin.read(3) == 1  
	{ 
		button=button+1 
		uart.print(button)
	}
}