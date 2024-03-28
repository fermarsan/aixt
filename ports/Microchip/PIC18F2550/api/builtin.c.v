// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (PIC18F2550)

module main

#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 8000000
#define true 1

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)


#define TRISa		TRISA	// port setup name equivalents
#define TRISb		TRISB
#define TRISc		TRISC

#define PORTa		PORTA	// port in name equivalents
#define PORTb		PORTB
#define PORTc		PORTC

#define LATa		LATA	// port out name equivalents
#define LATb		LATB
#define LATc		LATC

// pin configuration pits
#define a0_s    TRISAbits.TRISA0 
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

// pin input pits 
#define a0_i    PORTAbits.RA0       
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



fn init() {
    
}