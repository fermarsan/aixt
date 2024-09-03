/*
 * File:   7_Segmentos.c
 * Author: Andr�s Fajardo
 *
 * Created on 24 de diciembre de 2023, 12:11 AM
 */


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

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 8000000
#include "/home/aixt-project/ports/Microchip/PIC18F2550/api/builtin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F2550/api/machine/pin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F2550/api/time/sleep_ms.c"
#include "/home/aixt-project/ports/Microchip/PIC18F2550/api/time/sleep_us.c"

/*unsigned char display[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int contador;

void main(void) {
    ADCON1bits.PCFG = 0x0F;  // Coloca todos los pines como digitales
    TRISCbits.RC0 = 1;       // Puerto como entrada para manejar el 7 segmentos con un pulsador (CONTADOR+)
    TRISCbits.RC1 = 1;          // Puerto como entrada para manejar el 7 SEG con un pulsador (CONTADOR-)
    TRISB = 0x00;                   // Puerto B como salida
    LATB = 0x00;                    // Limpia al puerto B
    
    while (1){
        
        if (PORTCbits.RC0 == 1){
       
            while (PORTCbits.RC0 == 1);
            
            __delay_ms(20);
            contador++;
            LATB = display[contador];
            
            if(contador > 9){        
                contador = 9;
                LATB = display[contador];
            }
        }
               if (PORTCbits.RC1 == 1){ 
                   
                    while (PORTCbits.RC1 == 1);
            
            __delay_ms(20);
            
            contador--;
            LATB = display[contador];
            if (contador == -1){
                contador = 0;
            LATB = display[contador];
            } 
        }
    }
  return;
}
*/

unsigned char display[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int contador;

void main(void) {
    ADCON1bits.PCFG = 0x0F;  // Coloca todos los pines como digitales

    pin_setup(c0_s, in);       // Puerto como entrada para manejar el 7 segmentos con un pulsador (CONTADOR+)
    pin_setup(c1_s, in);          // Puerto como entrada para manejar el 7 SEG con un pulsador (CONTADOR-)

    // CONFIGURAMOS EL PUERTO B COMO SALIDA

    pin_setup(b0_s, out);
    pin_setup(b1_s, out);
    pin_setup(b2_s, out);
    pin_setup(b3_s, out);
    pin_setup(b4_s, out);
    pin_setup(b5_s, out);
    pin_setup(b6_s, out);
    pin_setup(b7_s, out);

    // LIMPIAMOS EL PUERTO B

    pin_write(b0, 0);
    pin_write(b1, 0);
    pin_write(b2, 0);
    pin_write(b3, 0);
    pin_write(b4, 0);
    pin_write(b5, 0);
    pin_write(b6, 0);
    pin_write(b7, 0);
   
   
    while (1){
        
        if (pin_read(c0_i) == 1){
       
            while (pin_read(c0_i) == 1);
            
            sleep_ms(20);
            contador++;
            LATB = display[contador];
            
            if(contador > 9){        
                contador = 9;
                LATB = display[contador];
            }
        }
               if (pin_read(c1_i) == 1){ 
                   
                    while (pin_read(c1_i) == 1);
            
            sleep_ms(20);
            
            contador--;
            LATB = display[contador];
            if (contador == -1){
                contador = 0;
            LATB = display[contador];
            } 
        }
    }
  return;
}