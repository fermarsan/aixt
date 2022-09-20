#include "./machine.h"
#include "./time.h"

int main(void) {
    // Port A access
    AD1PCFG = 0xFFFF; // set to digital I/O (not analog)
    
    pin(A5,OUT);
    pin(A6,OUT);
    
    while(1){
        pinHigh(A6);
        sleep_ms(500);

        pinWrite(A5,0);
        sleep_ms(500);

        pinWrite(A5,1);
        sleep_ms(500);
        
        pinLow(A6);
        sleep_ms(500);
    }
    return 0;
}