

// Porjects for the PIC16F83A

#include "../../api/builtin.c.v"
#include "../../api/pin/pin.c.v"
#include "../../api/pin/setup.c.v"
#include "../../api/pin/high.c.v"
#include "../../api/pin/low.c.v"
#include "../../api/pin/write.c.v"
#include "../../api/time/sleep_ms.c.v"
#include "../../api/time/sleep_us.c.v"

void main(void) {
    
    ADCON1bits.PCFG = 0b00000110;  // Se defien todos los pines como I/O digitales
    
    pin__setup(b4, out);
    
    pin__write(b4, 0);
    
    while(1){
    
        pin__high(b4);
        time__sleep_ms(200);
        pin__low(b4);
        time__sleep_ms(200);
                               
    }
}
