// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (PIC18F4550)

module main

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define _XTAL_FREQ 20000000


// CONFIG1L
#pragma config PLLDIV = 5         // 20 MHz PLL Prescaler Selection bits (Divide by 5 (20 MHz oscillator input))
#pragma config CPUDIV = OSC1_PLL2 // 96MHz PLL Src: /2=48MHz, /3=32MHz, /6=16MHz, /12=8MHz, /24=4MHz, /48=2MHz
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
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
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
@[as_macro] pub const a0 =_s    TRISAbits.TRISA0 
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

// pin input pits 
@[as_macro] pub const a0 =_i    PORTAbits.RA0       
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



