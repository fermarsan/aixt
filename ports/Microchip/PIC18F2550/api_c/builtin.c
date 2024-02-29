// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (PIC18F2550) 

#define a_s     TRISA            // pin configuration pits
#define a0_s    TRISAbits.TRISA0 
#define a1_s    TRISAbits.TRISA1 
#define a2_s    TRISAbits.TRISA2 
#define a3_s    TRISAbits.TRISA3
#define a4_s    TRISAbits.TRISA4 
#define a5_s    TRISAbits.TRISA5 
#define a6_s    TRISAbits.TRISA6 

// #define b_s     TRISB
#define b0_s    TRISBbits.TRISB0 
#define b1_s    TRISBbits.TRISB1 
#define b2_s    TRISBbits.TRISB2 
#define b3_s    TRISBbits.TRISB3 
#define b4_s    TRISBbits.TRISB4 
#define b5_s    TRISBbits.TRISB5 
#define b6_s    TRISBbits.TRISB6 
#define b7_s    TRISBbits.TRISB7 

// #define c_s     TRISC
#define c0_s    TRISCbits.TRISC0 
#define c1_s    TRISCbits.TRISC1 
#define c2_s    TRISCbits.TRISC2 
#define c4_s    TRISCbits.TRISC4 
#define c5_s    TRISCbits.TRISC5 
#define c6_s    TRISCbits.TRISC6 
#define c7_s    TRISCbits.TRISC7 

//#define a_i     PORTA        // pin input pits 
#define a0_i    PORTAbits.RA0       
#define a1_i    PORTAbits.RA1 
#define a2_i    PORTAbits.RA2 
#define a3_i    PORTAbits.RA3 
#define a4_i    PORTAbits.RA4 
#define a5_i    PORTAbits.RA5 
#define a6_i    PORTAbits.RA6 

//#define b_i     PORTB
#define b0_i    PORTBbits.RB0 
#define b1_i    PORTBbits.RB1 
#define b2_i    PORTBbits.RB2 
#define b3_i    PORTBbits.RB3 
#define b4_i    PORTBbits.RB4 
#define b5_i    PORTBbits.RB5 
#define b6_i    PORTBbits.RB6 
#define b7_i    PORTBbits.RB7 

//#define c_i     PORTC 
#define c0_i    PORTCbits.RC0 
#define c1_i    PORTCbits.RC1 
#define c2_i    PORTCbits.RC2 
#define c4_i    PORTCbits.RC4 
#define c5_i    PORTCbits.RC5 
#define c6_i    PORTCbits.RC6 
#define c7_i    PORTCbits.RC7 

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
