// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 8000000

#include <xc.h>

#include "../../api/builtin.c"
#include "../../api/machine/pin.c"
#include "../../api/time/sleep_s.c"
#include "../../api/time/sleep_ms.c"
#include "../../api/time/sleep_us.c"

void main(void) 
{
    pin_setup(b0_s,0);
    pin_setup(b1_s,1);
    pin_write(b0_s,0);
   
    
    while(1)
    {
        if(b1 == 1)
        {
            pin_high(b0);
        }
        else
        {
            pin_low(b0);
        }    
    }
    
    return;
}
