

// Projects for the PIC16F873A

#include "../../api/builtin.c.v"
#include "../../api/pin/pin.c.v"
#include "../../api/pin/setup.c.v"
#include "../../api/pin/high.c.v"
#include "../../api/pin/low.c.v"
#include "../../api/pin/write.c.v"



void main(void) {
   
    pin__setup(c4,out);
    pin__setup(c5,out);
    pin__setup(c6,out);
    pin__setup(b5,in);
    pin__setup(b6,in);
    
    pin__write(c4,0);
    pin__write(c5,0);
    pin__write(c6,0);
    pin__write(b5,0);
    pin__write(b6,0);
    
    while(1){
        
        if(b5 == 1){
            
            pin__high(c4);
            pin__high(c5);
            pin__high(c6);
        }
        
        else if(b6 == 1){
            
            pin__low(c4);
            pin__low(c5);
            pin__low(c6);
        }
    
    
    
    }
            
}
