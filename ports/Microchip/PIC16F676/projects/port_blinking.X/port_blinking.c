
// Projects for ports the PIC16F676

#include "../../api_c/builtin.c"
#include "../../api_c/machine/port.c"
#include "../../api_c/time/sleep_ms.c"

void main(void) {
    
    port.setup(port.c,0b00000000);
    
    while(1){
        
        port.write(port.c,0b010101);
        sleep_ms(500);
        port.write(port.c,0b101010);
        sleep_ms(500);      
        
    }
   
}
