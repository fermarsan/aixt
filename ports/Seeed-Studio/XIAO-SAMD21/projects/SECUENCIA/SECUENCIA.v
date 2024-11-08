import time {sleep_ms} 
import pin 

pin.setup(3, pin.output)    
pin.setup(4, pin.output)    
pin.setup(5, pin.output)    

for{
    pin.high(3)     
    sleep_ms(250)   
    pin.high(4)     
    sleep_ms(250)   
    pin.high(5)     
    sleep_ms(250)   
    pin.low(3)      
    sleep_ms(250)  
    pin.low(4)      
    sleep_ms(250)   
    pin.low(5)      
    sleep_ms(250)   
}