import pin
import adc
import uart

__global (
    val = 0
    )

pin.setup(3, pin.output)
pin.setup(4, pin.output)
uart.setup(9600)

for {
    val=adc.read(8)
    uart.println(val)    
    if  val>=750 && val<=800 {
        pin.high(3)
        pin.low(4)  
    } else if val>=1000 {
        pin.low(3)
        pin.high(4)
    } else {
        pin.low(3)
        pin.low(4) 
    }
}