#define _XTAL_FREQ 4000000

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

// volatile unsigned char __temp_byte_0 __at(0x4F);
// volatile unsigned char __temp_byte_1 __at(0x4E);