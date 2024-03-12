

// Projects for the PIC16F873A


#include "../../api_c/builtin.c"
#include "../../api_c/machine/port.c"
#include "../../api_c/time/sleep_ms.c"

void main(void) {
    
    port_setup(b,0b00000000);
    
    while(1) {
        
        port_write(b,0b01010101);
        sleep_ms(500);
        port_write(b,0b10101010);
        sleep_ms(500);      
        
    }

}
