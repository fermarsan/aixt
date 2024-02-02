/*
 * File:   Ledbasico.c
 * Author: jean carlo
 *
 * Created on 31 de enero de 2024, 07:30 PM
 */


// CONFIG1H
#pragma config OSC = HS       // Oscillator Selection bits (RC oscillator w/ OSC2 configured as RA6)
#pragma config OSCS = OFF       // Oscillator System Clock Switch Enable bit (Oscillator system clock switch option is disabled (main oscillator is source))

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF         // Brown-out Reset Enable bit (Brown-out Reset enabled)
#pragma config BORV = 20       // Brown-out Reset Voltage bits (VBOR set to 2.0V)

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
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/builtin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/machine/pin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/time/sleep_ms.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/time/sleep_us.c"


/*void main(void) {
   ADCON1bits.PCFG = 0x0F;     //TODAS LOS PINES COMO DIGITALES
   TRISBbits.RB0 = 0;          //CONFIGURAMOS EL PIN B0 COMO SALIDA
    LATBbits.LB0  = 0;          //LIMPIAMOS EL BIT B0
    while(1){ 
        LATBbits.LB0 = 1;       //PIN_HIGH
          __delay_ms(1000);   
        LATBbits.LB0 = 0;       //PIN_LOW
          __delay_ms(1000);   
    }
  return;
}*/


void main(void) {
    ADCON1bits.PCFG = 0x0F;     //TODAS LOS PINES COMO DIGITALES
    pin_setup(b0_s, out);       //CONFIGURAMOS EL PIN B0 COMO SALIDA
    pin_write(b0, 0);           //LIMPIAMOS EL BIT B0
    while(1){ 
        pin_high(b0);       //PIN HIGH
          sleep_ms(1000);   
        pin_low(b0);        //PIN LOW
          sleep_ms(1000);   
    }
  return;
}