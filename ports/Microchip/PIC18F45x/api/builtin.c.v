// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (PIC18F452) 

module main

#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 8000000
#define true 1

// CONFIG1H
#pragma config OSC = HS       // Oscillator Selection bits (RC oscillator w/ OSC2 configured as RA6)
#pragma config OSCS = OFF       // Oscillator System Clock Switch Enable bit (Oscillator system clock switch option is disabled (main oscillator is source))

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF         // Brown-out Reset Enable bit (Brown-out Reset enabled)
#pragma config BORV = 20        // Brown-out Reset Voltage bits (VBOR set to 2.0V)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 128      // Watchdog Timer Postscale Select bits (1:128)

// CONFIG3H
#pragma config CCP2MUX = ON     // CCP2 Mux bit (CCP2 input/output is multiplexed with RC1)

// CONFIG4L
#pragma config STVR = ON        // Stack Full/Underflow Reset Enable bit (Stack Full/Underflow will cause RESET)
#pragma config LVP = ON         // Low Voltage ICSP Enable bit (Low Voltage ICSP enabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-001FFFh) not code protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-001FFFh) not write protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-001FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from Table Reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from Table Reads executed in other blocks)


#include <xc.h>
#define _XTAL_FREQ 8000000
   
#define a0_s    TRISAbits.TRISA0    // pin configuration pits
#define a1_s    TRISAbits.TRISA1 
#define a2_s    TRISAbits.TRISA2 
#define a3_s    TRISAbits.TRISA3
#define a4_s    TRISAbits.TRISA4 
#define a5_s    TRISAbits.TRISA5 
#define a6_s    TRISAbits.TRISA6 

#define b0_s    TRISBbits.TRISB0 
#define b1_s    TRISBbits.TRISB1 
#define b2_s    TRISBbits.TRISB2 
#define b3_s    TRISBbits.TRISB3 
#define b4_s    TRISBbits.TRISB4 
#define b5_s    TRISBbits.TRISB5 
#define b6_s    TRISBbits.TRISB6 
#define b7_s    TRISBbits.TRISB7 

#define c0_s    TRISCbits.TRISC0 
#define c1_s    TRISCbits.TRISC1 
#define c2_s    TRISCbits.TRISC2 
#define c4_s    TRISCbits.TRISC4 
#define c5_s    TRISCbits.TRISC5 
#define c6_s    TRISCbits.TRISC6 
#define c7_s    TRISCbits.TRISC7 

#define d0_s    TRISCbits.TRISD0 
#define d1_s    TRISCbits.TRISD1 
#define d2_s    TRISCbits.TRISD2 
#define d4_s    TRISCbits.TRISD4 
#define d5_s    TRISCbits.TRISD5 
#define d6_s    TRISCbits.TRISD6 
#define d7_s    TRISCbits.TRISD7 

#define e0_s    TRISCbits.TRISE0 
#define e1_s    TRISCbits.TRISE1 
#define e2_s    TRISCbits.TRISE2 


#define a0_i    PORTAbits.RA0       // pin input pits 
#define a1_i    PORTAbits.RA1 
#define a2_i    PORTAbits.RA2 
#define a3_i    PORTAbits.RA3 
#define a4_i    PORTAbits.RA4 
#define a5_i    PORTAbits.RA5 
#define a6_i    PORTAbits.RA6 

#define b0_i    PORTBbits.RB0 
#define b1_i    PORTBbits.RB1 
#define b2_i    PORTBbits.RB2 
#define b3_i    PORTBbits.RB3 
#define b4_i    PORTBbits.RB4 
#define b5_i    PORTBbits.RB5 
#define b6_i    PORTBbits.RB6 
#define b7_i    PORTBbits.RB7 

#define c0_i    PORTCbits.RC0 
#define c1_i    PORTCbits.RC1 
#define c2_i    PORTCbits.RC2 
#define c4_i    PORTCbits.RC4 
#define c5_i    PORTCbits.RC5 
#define c6_i    PORTCbits.RC6 
#define c7_i    PORTCbits.RC7 

#define d0_i    TRISCbits.TRISD0 
#define d1_i    TRISCbits.TRISD1 
#define d2_i    TRISCbits.TRISD2 
#define d4_i    TRISCbits.TRISD4 
#define d5_i   TRISCbits.TRISD5 
#define d6_i    TRISCbits.TRISD6 
#define d7_i    TRISCbits.TRISD7 

#define e0_i    TRISCbits.TRISE0 
#define e1_i    TRISCbits.TRISE1 
#define e2_i    TRISCbits.TRISE2 

#define a0      LATAbits.LATA0      // pin output pits
#define a1      LATAbits.LATA1 
#define a2      LATAbits.LATA2 
#define a3      LATAbits.LATA3 
#define a4      LATAbits.LATA4 
#define a5      LATAbits.LATA5 
#define a6      LATAbits.LATA6 

#define b0      LATBbits.LATB0 
#define b1      LATBbits.LATB1 
#define b2      LATBbits.LATB2 
#define b3      LATBbits.LATB3 
#define b4      LATBbits.LATB4 
#define b5      LATBbits.LATB5 
#define b6      LATBbits.LATB6 
#define b7      LATBbits.LATB7 

#define c0      LATCbits.LATC0 
#define c1      LATCbits.LATC1 
#define c2      LATCbits.LATC2 
#define c4      LATCbits.LATC4 
#define c5      LATCbits.LATC5 
#define c6      LATCbits.LATC6 
#define c7      LATCbits.LATC7 

#define d1    TRISCbits.TRISD0 
#define d2    TRISCbits.TRISD1 
#define d3    TRISCbits.TRISD2 
#define d4    TRISCbits.TRISD4 
#define d5   TRISCbits.TRISD5 
#define d6    TRISCbits.TRISD6 
#define d7    TRISCbits.TRISD7 

#define e0    TRISCbits.TRISE0 
#define e1    TRISCbits.TRISE1 
#define e2    TRISCbits.TRISE2 

fn init() {
	
}