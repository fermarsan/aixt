import pin
import adc

a := u16 (0)

pin.setup(c0, pin.output)
pin.setup(c1, pin.output)
pin.setup(c2, pin.output)
pin.setup(c3, pin.output)
pin.setup(c4, pin.output)
pin.setup(c5, pin.output)

pin.write(c0,0)	
pin.write(c1,0)
pin.write(c2,0)
pin.write(c3,0)
pin.write(c4,0)
pin.write(c5,0)


adc.setup()

for{

	a = adc.read(4)
	

	if a >= 1020 {

		pin.high(c0)
        pin.high(c1)
        pin.high(c2)
        pin.high(c3)
        pin.high(c4)
        pin.high(c5)

	}

	else if  a >= 820 {
            
        pin.high(c0)
        pin.high(c1)
        pin.high(c2)
        pin.high(c3)
        pin.high(c4)
        pin.low(c5)
  
    }
        
    else if  a >= 620 {
            
    	pin.high(c0)
    	pin.high(c1)
    	pin.high(c2)
    	pin.high(c3)
    	pin.low(c4)
    	pin.low(c5)   

    }
        
    else if  a >= 420 {
            
        pin.high(c0)
        pin.high(c1)
        pin.high(c2)
        pin.low(c3)
        pin.low(c4)
        pin.low(c5)  
  
    }

	else if  a >= 220 {
            
        pin.high(c0)
        pin.high(c1)
        pin.low(c2)
        pin.low(c3)
        pin.low(c4)
        pin.low(c5)  
   
     }
        
    else if  a >= 120 {
            
        pin.high(c0)
        pin.low(c1)
        pin.low(c2)
        pin.low(c3)
        pin.low(c4)
        pin.low(c5)
      
    }
        
     else {
            
        pin.low(c0)
        pin.low(c1)
        pin.low(c2)
        pin.low(c3)
        pin.low(c4)
        pin.low(c5)       
    }
        

}