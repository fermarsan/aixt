


// Projects for adc the PIC16F676

#include "../../api_c/builtin.c"
#include "../../api_c/machine/pin.c"

void main(void) {
    
    ANSEL = 0b00000000; // Todas los pin son I/O digitales
    
    pin_setup(c2, in);
    pin_setup(c4, in);
    pin_setup(c1, out);
    pin_setup(c0, out);
 
    pin_write(c0, 0);   // Inicia la salida C0 en cero
    pin_write(c1, 0);   // Inicia la salida C1 en cero
    
    while(1){
        
        if(c2 == 1){
            
            pin_high(c1);
            pin_high(c0);
        }
        
        else if(c4 == 1){
            
            pin_low(c1);
            pin_low(c0);
        }
    
    
    }
        
}