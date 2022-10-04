#include "./machine.h"

int main(void) {
    // Port A access
    AD1PCFG = 0xFFFF; // set to digital I/O (not analog)
    pin(A5,OUT);
    pin(A6,OUT);
    pin(D13,IN);
    
    while(1){
        if(pinRead(D13)==1){
            pinHigh(A6);
            pinLow(A5);
        }
        else{
            pinHigh(A5);
            pinLow(A6);
        }
    }
    return 0;
}