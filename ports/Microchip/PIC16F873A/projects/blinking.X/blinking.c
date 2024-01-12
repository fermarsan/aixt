// PIC16F873A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 8000000

#include "../../api/builtin.c"
#include "../../api/machine/pin.c"
#include "../../api/time/sleep_ms.c"
#include "../../api/time/sleep_us.c"

void main(void) {
    
    ADCON1bits.PCFG = 0b00000110;  // Se defien todos los pines como I/O digitales
    
    pin_setup(b0_s, out);
    pin_setup(c7_s, out);
    
    pin_write(b0, 0);
    pin_write(c7, 0);
    
    while(1){
    
        pin_high(b0);
        sleep_ms(200);
        pin_low(b0);
        sleep_ms(200);
                               
    }
}
