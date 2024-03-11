// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (PIC16F886 port)
#define an0    a0           
#define an1    a1        
#define an2    a2        
#define an3    a3       
#define an4    a5       
#define an8    b2
#define an9    b3       
#define an10   b1
#define an11   b4
#define an12   b0
#define an13   b5

#define a0_s    TRISAbits.TRISA0    // pin configuration pits
#define a1_s    TRISAbits.TRISA1 
#define a2_s    TRISAbits.TRISA2 
#define a3_s    TRISAbits.TRISA3
#define a4_s    TRISAbits.TRISA4 
#define a5_s    TRISAbits.TRISA5 
#define a6_s    TRISAbits.TRISA6 
#define a7_s    TRISAbits.TRISA7 

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
#define c3_s    TRISCbits.TRISC3 
#define c4_s    TRISCbits.TRISC4 
#define c5_s    TRISCbits.TRISC5 
#define c6_s    TRISCbits.TRISC6 
#define c7_s    TRISCbits.TRISC7 


#define a0    PORTAbits.RA0       // pin input and output pits 
#define a1    PORTAbits.RA1 
#define a2    PORTAbits.RA2 
#define a3    PORTAbits.RA3 
#define a4    PORTAbits.RA4 
#define a5    PORTAbits.RA5 
#define a6    PORTAbits.RA6 
#define a7    PORTAbits.RA7 


#define b0    PORTBbits.RB0 
#define b1    PORTBbits.RB1 
#define b2    PORTBbits.RB2 
#define b3    PORTBbits.RB3 
#define b4    PORTBbits.RB4 
#define b5    PORTBbits.RB5 
#define b6    PORTBbits.RB6 
#define b7    PORTBbits.RB7 


#define c0    PORTCbits.RC0 
#define c1    PORTCbits.RC1 
#define c2    PORTCbits.RC2 
#define c3    PORTCbits.RC3 
#define c4    PORTCbits.RC4 
#define c5    PORTCbits.RC5 
#define c6    PORTCbits.RC6 
#define c7    PORTCbits.RC7 
