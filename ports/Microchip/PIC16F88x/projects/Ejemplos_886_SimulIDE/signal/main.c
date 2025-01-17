// This C code was automatically generated by Aixt Project
// Device = PIC16F886
// Board = Nothing
// Backend = c


#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define _XTAL_FREQ 10000000
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF		// Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
#define time__sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory
#define time__sleep_us(TIME)    __delay_us(TIME)  // implementing by a macro for saving memory
#define time__sleep(TIME)    __delay_ms(TIME*1024)  // implementing by a macro for saving memory
#define port__a		A	// port name constants
#define port__b		B
#define port__c		C
#define port__e		E
#define	port__all_inputs	0xFF	// port mode constants
#define	port__all_outputs	0x00
#define TRISport__a		TRISA	// port setup name equivalents
#define TRISport__b		TRISB
#define TRISport__c		TRISC
#define TRISport__e		TRISE
#define PORTport__a		PORTA	// port name equivalents
#define PORTport__b		PORTB
#define PORTport__c		PORTC
#define PORTport__e		PORTE
#define port__write(PORT_NAME, VALUE)  PORT ## PORT_NAME = (uint8_t)VALUE
#define port__setup(PORT_NAME, VALUE)   TRIS ## PORT_NAME = VALUE
#define port__read(PORT_NAME)  PORT ## PORT_NAME

int __t1;



void main(void) {

long signal[15] = {1, 2, 4, 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2, 1};
port__setup(port__b, port__all_outputs);
while(true) {
for(int __t1 = 0; __t1 < 15; __t1++) {
long x;
x = signal[__t1];
port__write(port__b, x);
time__sleep_ms(10);
}
}
}