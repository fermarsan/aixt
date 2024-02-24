/*
 * File:   ADC_2550.c
 * Author: Andr�s Fajardo
 *
 * Created on 2 de enero de 2024, 05:12 PM
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


#define _XTAL_FREQ 8000000
#include <xc.h>
#include "/home/aixt-project/ports/Microchip/PIC18F2550/api/builtin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F2550/api/machine/pin.c"
#include "/home/aixt-project/ports/Microchip/PIC18F2550/api/machine/adc.c"
#include "/home/aixt-project/ports/Microchip/PIC18F2550/api/time/sleep_ms.c"

void main(void) {

/*  ADCON1 = 0x00;                          // Vref = VSS y GND, Configuracion de entradas analogicas
    ADCON0 = 0x00;                          // Seleccion del canal, Habilitaci�n del conversor
    ADCON2 = 0x97;                          // Tiempo de adquisicion, Justificacion hacia la derecha
    ADCON0bits.ADON = 1;                    // Enciende el conversor  */

    adc_setup();

    
/*  TRISB = 0x00;
    TRISC = 0x00;
    LATB = 0x00;
    LATC = 0X00;  */
    
// CONFIGURAMOS EL PUERTO B COMO SALIDA

    pin_setup(b0_s, out);
    pin_setup(b1_s, out);
    pin_setup(b2_s, out);
    pin_setup(b3_s, out);
    pin_setup(b4_s, out);
    pin_setup(b5_s, out);
    pin_setup(b6_s, out);
    pin_setup(b7_s, out);

    // CONFIGURAMOS EL PUERTO C COMO SALIDA

    pin_setup(c0_s, out);
    pin_setup(c1_s, out);
    pin_setup(c2_s, out);
    pin_setup(c3_s, out);
    pin_setup(c4_s, out);
    pin_setup(c5_s, out);
    pin_setup(c6_s, out);
    pin_setup(c7_s, out);

    // LIMPIAMOS EL PUERTO B

    pin_write(b0, 0);
    pin_write(b1, 0);
    pin_write(b2, 0);
    pin_write(b3, 0);
    pin_write(b4, 0);
    pin_write(b5, 0);
    pin_write(b6, 0);
    pin_write(b7, 0);

        // LIMPIAMOS EL PUERTO B

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
       /*  ADCON0bits.GO_DONE = 1;             // Inicia la conversion
        while(ADCON0bits.GO_DONE == 1);     // Espera a que termine la conversion
        LATB = ADRESL;                      // Muestra el dato de la parte baja en el puerto B
        LATC = ADRESH;                      // Muestra el dato de la parte alta en el puerto C
        __delay_ms(10); */


        adc_read(0);
        valor = adc_reading();
        LATB = valor & 0xFF;                      // Muestra el dato de la parte baja en el puerto B
        LATC = (valor>>8) & 0x03;                 // Muestra el dato de la parte alta en el puerto C
        sleep_ms(10);
    }
}
