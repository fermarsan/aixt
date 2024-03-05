// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 8000000

#include <xc.h>

#include "../../api/builtin.c"
#include "../../api/machine/pin.c"
#include "../../api/time/sleep_s.c"
#include "../../api/time/sleep_ms.c"
#include "../../api/time/sleep_us.c"

void main(void) 
{
    ANSELH = 0b00000000; // configura las entradas o salidas como digitales desde AN8 hasta AN13
    ANSEL = 0b00000000; // configura las entradas o salidas como digitales desde AN0 hatas AN7
    pin_setup(a1_s,0);
    pin_setup(b3_s,1);
    pin_write(a1_s,0);
   
    
    while(1)
    {
        if(b3 == 1)
        {
            pin_high(a1);
        }
        else
        {
            pin_low(a1);
        }    
    }
}
