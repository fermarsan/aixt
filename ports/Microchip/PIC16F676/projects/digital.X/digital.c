


// Projects for adc the PIC16F676

#include "../../api/builtin.c.v"
#include "../../api/pin/pin.c.v"
#include "../../api/pin/setup.c.v"
#include "../../api/pin/high.c.v"
#include "../../api/pin/low.c.v"
#include "../../api/pin/read.c.v"
#include "../../api/pin/write.c.v"

void main(void) {
    
    ANSEL = 0b00000000; // Todas los pin son I/O digitales
    
    pin__setup(c2, in);
    pin__setup(c4, in);
    pin__setup(c1, out);
    pin__setup(c0, out);
 
    pin__write(c0, 0);   // Inicia la salida C0 en cero
    pin__write(c1, 0);   // Inicia la salida C1 en cero
    
    while(1){
        
        if(c2 == 1){
            
            pin__high(c1);
            pin__high(c0);
        }
        
        else if(c4 == 1){
            
            pin__low(c1);
            pin__low(c0);
        }
    
    
    }
        
}