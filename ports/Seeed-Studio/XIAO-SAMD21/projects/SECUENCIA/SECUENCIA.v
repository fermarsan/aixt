import time {sleep_ms} 
import pin 

pin.setup(3, output)    
pin.setup(4, output)    
pin.setup(5, output)    

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