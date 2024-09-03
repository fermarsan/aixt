/*
 * File:   PWM_452.c
 * Author: jean carlo
 *
 * Created on 6 de enero de 2024, 09:37 PM
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
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/machine/adc.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/machine/pwm.c"
#include "/home/aixt-project/ports/Microchip/PIC18F452/api/time/sleep_ms.c"

void main()
{
/*  ADCON1 = 0x8E;                        // Configura el pin RA0 como analogico
    ADCON0 = 0xC0;                          // Selecciona el canal 0 del ADC                           
    ADCON0bits.ADON = 1;                    // Habilita el conversor */
    adc_setup();

 /* PR2 = 0xC;                             // Valor del periodo
    CCPR1L = 0;                             // Inicia el CCP1 en 0
    TRISCbits.TRISC2 = 0;                   // Pin C2 como salida
    T2CON = 0x03;                           // Configuracion del timer 2
    CCP1CON = 0x0C;                         // Configura el CCP1 en modo PWM
    TMR2 = 0;                               // Timer 2 en 0
    T2CONbits.TMR2ON = 1;                   // Timer 2 ON
    */
    pwm_setup(1,2);    
    
    while(1)
    {
        /* ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE == 1); */
        adc_read(0);

        /*int valor_adc = ADRES; */
        int valor_adc = adc_reading();

        /*unsigned char valor_pwm = map(valor_adc, 0, 1023, 0, 50);
        CCPR1L = (valor_pwm >> 2);*/
        pwm_write(valor_adc,1);

    }
}