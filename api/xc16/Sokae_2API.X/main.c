#include "./machine.h"
#include "./time.h"

char c;
uint32_t x; 

#define BAUD    9600UL

int main(void) {

    uart2(9600);
    
    
    
    uart2_put('S');
    uart2_put('T');
    uart2_put('A');
    uart2_put('R');
    uart2_put('T');
    uart2_put(':');
    uart2_put(' ');

    while(1){
        // c = uart2Get();
        // uart2Put(c+1);
        // x = 4000000 / (4*BAUD) - 1;
        
        // for(int i=1;i<=3;i++){
        //     c = (char)(x % 10);
        //     x = (uint32_t)(x/10);
        //     uart2Put(c+48);
             sleep_ms(500);
        // }
        uart2_write("Sokae project....   ");
        
    }
    return 0;
}