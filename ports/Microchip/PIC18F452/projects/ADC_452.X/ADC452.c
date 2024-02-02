/*
 * File:   ADC452.c
 * Author: jean carlo
 *
 * Created on 6 de enero de 2024, 05:51 PM
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


#define _XTAL_FREQ 8000000
#include <xc.h>
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/builtin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/machine/pin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/time/sleep_ms.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/machine/adc.c"

/*void main(void) {
    ADCON1 = 0x8E;                          // Vref = VSS y GND, Configuracion de entradas analogicas
    ADCON0 = 0xC0;                          // Seleccion del canal, Habilitaci�n del conversor
    ADCON0bits.ADON = 1;                    // Enciende el conversor
    
    TRISB = 0x00;
    TRISC = 0x00;
    LATB = 0x00;
    LATC = 0X00;
    
    while(1)
    {
        ADCON0bits.GO_DONE = 1;             // Inicia la conversion
        while(ADCON0bits.GO_DONE == 1);     // Espera a que termine la conversion
        LATB = ADRESL;                      // Muestra el dato de la parte baja en el puerto B
        LATC = ADRESH;                      // Muestra el dato de la parte alta en el puerto C
        __delay_ms(10);
    }
}*/

void main(void) {
    
    adc_setup();
    
   // TRISB = 0x00;
   // Puerto b como salida
    pin_setup(b0_s, out);
    pin_setup(b1_s, out);
    pin_setup(b2_s, out);
    pin_setup(b3_s, out);
    pin_setup(b4_s, out);
    pin_setup(b5_s, out);
    pin_setup(b6_s, out);
    pin_setup(b7_s, out);

  // TRISC = 0x00; 
  //PUERTO C como salida
    pin_setup(c0_s, out);
    pin_setup(c1_s, out);
    pin_setup(c2_s, out);
    pin_setup(c3_s, out);
    pin_setup(c4_s, out);
    pin_setup(c5_s, out);
    pin_setup(c6_s, out);
    pin_setup(c7_s, out);

    //LATB = 0x00;
    // LIMPIAMOS EL PUERTO B

    pin_write(b0, 0);
    pin_write(b1, 0);
    pin_write(b2, 0);
    pin_write(b3, 0);
    pin_write(b4, 0);
    pin_write(b5, 0);
    pin_write(b6, 0);
    pin_write(b7, 0);

    //LATC = 0X00;
    // LIMPIAMOS EL PUERTO C

    pin_write(c0, 0);
    pin_write(c1, 0);
    pin_write(c2, 0);
    pin_write(c3, 0);
    pin_write(c4, 0);
    pin_write(c5, 0);
    pin_write(c6, 0);
    pin_write(c7, 0);
    
    while(1)
    {
        adc_read(0);
        valor = adc_reading();
        LATB = valor & 0xFF;                      // Muestra el dato de la parte baja en el puerto B
        LATC = (valor>>8) & 0x03;                      // Muestra el dato de la parte alta en el puerto C
        sleep_ms(10);
    }
}
