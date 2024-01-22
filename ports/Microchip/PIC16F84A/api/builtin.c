// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (PIC16F84A port)
 
#define a0_s    TRISAbits.TRISA0    // pin configuration pits
#define a1_s    TRISAbits.TRISA1 
#define a2_s    TRISAbits.TRISA2 
#define a3_s    TRISAbits.TRISA3


#define b0_s    TRISBbits.TRISB0 
#define b1_s    TRISBbits.TRISB1 
#define b2_s    TRISBbits.TRISB2 
#define b3_s    TRISBbits.TRISB3 
#define b4_s    TRISBbits.TRISB4 
#define b5_s    TRISBbits.TRISB5 
#define b6_s    TRISBbits.TRISB6 
#define b7_s    TRISBbits.TRISB7 



#define a0    PORTAbits.RA0       // pin input and output pits 
#define a1    PORTAbits.RA1 
#define a2    PORTAbits.RA2 
#define a3    PORTAbits.RA3 


#define b0    PORTBbits.RB0 
#define b1    PORTBbits.RB1 
#define b2    PORTBbits.RB2 
#define b3    PORTBbits.RB3 
#define b4    PORTBbits.RB4 
#define b5    PORTBbits.RB5 
#define b6    PORTBbits.RB6 
#define b7    PORTBbits.RB7 