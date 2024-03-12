

// Projects for the PIC16F873A

#include "../../api_c/builtin.c.v"
#include "../../api_c/machine/pin.c"

void main(void) {
   
    pin_setup(c4,out);
    pin_setup(c5,out);
    pin_setup(c6,out);
    pin_setup(b5,in);
    pin_setup(b6,in);
    
    pin_write(c4,0);
    pin_write(c5,0);
    pin_write(c6,0);
    pin_write(b5,0);
    pin_write(b6,0);
    
    while(1){
        
        if(b5 == 1){
            
            pin_high(c4);
            pin_high(c5);
            pin_high(c6);
        }
        
        else if(b6 == 1){
            
            pin_low(c4);
            pin_low(c5);
            pin_low(c6);
        }
    
    
    
    }
            
}
