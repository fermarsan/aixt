import pin 
import adc 
__global (
    
	pot=0
)
__global (
    
	brillo=0
)
__global (
    
	led=3
)

pin.setup(3,pin.input)
pin.setup(6,pin.output)

