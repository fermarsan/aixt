
// Projects for ports the PIC16F676

#include "../../api/builtin.c.v"
#include "../../api/port/setup.c.v"
#include "../../api/port/read.c.v"
#include "../../api/port/write.c.v"
#include "../../api/time/sleep_ms.c.v"

void main(void) {
    
    port__setup(c,0b00000000);
    
    while(1){
        
        port__write(c,0b010101);
        time__sleep_ms(500);
        port__write(c,0b101010);
        time__sleep_ms(500);      
        
    }
   
}
