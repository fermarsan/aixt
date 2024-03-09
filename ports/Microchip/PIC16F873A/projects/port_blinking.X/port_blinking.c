

// Projects for the PIC16F873A


#include "../../api/builtin.c.v"
#include "../../api/port/setup.c.v"
#include "../../api/port/read.c.v"
#include "../../api/port/write.c.v"
#include "../../api/time/sleep_ms.c.v"

void main(void) {
    
    port__setup(b,0b00000000);
    
    while(1){
        
        port__write(b,0b01010101);
        time__sleep_ms(500);
        port__write(b,0b10101010);
        time__sleep_ms(500);      
        
    }

}
