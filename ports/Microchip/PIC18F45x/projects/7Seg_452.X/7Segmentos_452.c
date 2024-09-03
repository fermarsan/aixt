/*
 * File:   7Segmentos_452.c
 * Author: Jan carlo
 *
 * Created on 6 de enero de 2024, 11:08 PM
 */
    
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

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 8000000
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/builtin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/machine/pin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/time/sleep_ms.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/time/sleep_us.c"

/*
unsigned char display[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
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