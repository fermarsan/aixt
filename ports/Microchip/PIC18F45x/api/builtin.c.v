// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
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
   
@[as_macro] pub const a0 =_s    TRISAbits.TRISA0    // pin configuration pits
@[as_macro] pub const a1 =_s    TRISAbits.TRISA1 
@[as_macro] pub const a2 =_s    TRISAbits.TRISA2 
@[as_macro] pub const a3 =_s    TRISAbits.TRISA3
@[as_macro] pub const a4 =_s    TRISAbits.TRISA4 
@[as_macro] pub const a5 =_s    TRISAbits.TRISA5 
@[as_macro] pub const a6 =_s    TRISAbits.TRISA6 

@[as_macro] pub const b0 =_s    TRISBbits.TRISB0 
@[as_macro] pub const b1 =_s    TRISBbits.TRISB1 
@[as_macro] pub const b2 =_s    TRISBbits.TRISB2 
@[as_macro] pub const b3 =_s    TRISBbits.TRISB3 
@[as_macro] pub const b4 =_s    TRISBbits.TRISB4 
@[as_macro] pub const b5 =_s    TRISBbits.TRISB5 
@[as_macro] pub const b6 =_s    TRISBbits.TRISB6 
@[as_macro] pub const b7 =_s    TRISBbits.TRISB7 

@[as_macro] pub const c0 =_s    TRISCbits.TRISC0 
@[as_macro] pub const c1 =_s    TRISCbits.TRISC1 
@[as_macro] pub const c2 =_s    TRISCbits.TRISC2 
@[as_macro] pub const c4 =_s    TRISCbits.TRISC4 
@[as_macro] pub const c5 =_s    TRISCbits.TRISC5 
@[as_macro] pub const c6 =_s    TRISCbits.TRISC6 
@[as_macro] pub const c7 =_s    TRISCbits.TRISC7 

@[as_macro] pub const d0 =_s    TRISCbits.TRISD0 
@[as_macro] pub const d1 =_s    TRISCbits.TRISD1 
@[as_macro] pub const d2 =_s    TRISCbits.TRISD2 
@[as_macro] pub const d4 =_s    TRISCbits.TRISD4 
@[as_macro] pub const d5 =_s    TRISCbits.TRISD5 
@[as_macro] pub const d6 =_s    TRISCbits.TRISD6 
@[as_macro] pub const d7 =_s    TRISCbits.TRISD7 

@[as_macro] pub const e0 =_s    TRISCbits.TRISE0 
@[as_macro] pub const e1 =_s    TRISCbits.TRISE1 
@[as_macro] pub const e2 =_s    TRISCbits.TRISE2 


@[as_macro] pub const a0 =_i    PORTAbits.RA0       // pin input pits 
@[as_macro] pub const a1 =_i    PORTAbits.RA1 
@[as_macro] pub const a2 =_i    PORTAbits.RA2 
@[as_macro] pub const a3 =_i    PORTAbits.RA3 
@[as_macro] pub const a4 =_i    PORTAbits.RA4 
@[as_macro] pub const a5 =_i    PORTAbits.RA5 
@[as_macro] pub const a6 =_i    PORTAbits.RA6 

@[as_macro] pub const b0 =_i    PORTBbits.RB0 
@[as_macro] pub const b1 =_i    PORTBbits.RB1 
@[as_macro] pub const b2 =_i    PORTBbits.RB2 
@[as_macro] pub const b3 =_i    PORTBbits.RB3 
@[as_macro] pub const b4 =_i    PORTBbits.RB4 
@[as_macro] pub const b5 =_i    PORTBbits.RB5 
@[as_macro] pub const b6 =_i    PORTBbits.RB6 
@[as_macro] pub const b7 =_i    PORTBbits.RB7 

@[as_macro] pub const c0 =_i    PORTCbits.RC0 
@[as_macro] pub const c1 =_i    PORTCbits.RC1 
@[as_macro] pub const c2 =_i    PORTCbits.RC2 
@[as_macro] pub const c4 =_i    PORTCbits.RC4 
@[as_macro] pub const c5 =_i    PORTCbits.RC5 
@[as_macro] pub const c6 =_i    PORTCbits.RC6 
@[as_macro] pub const c7 =_i    PORTCbits.RC7 

@[as_macro] pub const d0 =_i    TRISCbits.TRISD0 
@[as_macro] pub const d1 =_i    TRISCbits.TRISD1 
@[as_macro] pub const d2 =_i    TRISCbits.TRISD2 
@[as_macro] pub const d4 =_i    TRISCbits.TRISD4 
@[as_macro] pub const d5 =_i   TRISCbits.TRISD5 
@[as_macro] pub const d6 =_i    TRISCbits.TRISD6 
@[as_macro] pub const d7 =_i    TRISCbits.TRISD7 

@[as_macro] pub const e0 =_i    TRISCbits.TRISE0 
@[as_macro] pub const e1 =_i    TRISCbits.TRISE1 
@[as_macro] pub const e2 =_i    TRISCbits.TRISE2 

@[as_macro] pub const a0 =      LATAbits.LATA0      // pin output pits
@[as_macro] pub const a1 =      LATAbits.LATA1 
@[as_macro] pub const a2 =      LATAbits.LATA2 
@[as_macro] pub const a3 =      LATAbits.LATA3 
@[as_macro] pub const a4 =      LATAbits.LATA4 
@[as_macro] pub const a5 =      LATAbits.LATA5 
@[as_macro] pub const a6 =      LATAbits.LATA6 

@[as_macro] pub const b0 =      LATBbits.LATB0 
@[as_macro] pub const b1 =      LATBbits.LATB1 
@[as_macro] pub const b2 =      LATBbits.LATB2 
@[as_macro] pub const b3 =      LATBbits.LATB3 
@[as_macro] pub const b4 =      LATBbits.LATB4 
@[as_macro] pub const b5 =      LATBbits.LATB5 
@[as_macro] pub const b6 =      LATBbits.LATB6 
@[as_macro] pub const b7 =      LATBbits.LATB7 

@[as_macro] pub const c0 =      LATCbits.LATC0 
@[as_macro] pub const c1 =      LATCbits.LATC1 
@[as_macro] pub const c2 =      LATCbits.LATC2 
@[as_macro] pub const c4 =      LATCbits.LATC4 
@[as_macro] pub const c5 =      LATCbits.LATC5 
@[as_macro] pub const c6 =      LATCbits.LATC6 
@[as_macro] pub const c7 =      LATCbits.LATC7 

@[as_macro] pub const d1 =    TRISCbits.TRISD0 
@[as_macro] pub const d2 =    TRISCbits.TRISD1 
@[as_macro] pub const d3 =    TRISCbits.TRISD2 
@[as_macro] pub const d4 =    TRISCbits.TRISD4 
@[as_macro] pub const d5 =   TRISCbits.TRISD5 
@[as_macro] pub const d6 =    TRISCbits.TRISD6 
@[as_macro] pub const d7 =    TRISCbits.TRISD7 

@[as_macro] pub const e0 =    TRISCbits.TRISE0 
@[as_macro] pub const e1 =    TRISCbits.TRISE1 
@[as_macro] pub const e2 =    TRISCbits.TRISE2 

