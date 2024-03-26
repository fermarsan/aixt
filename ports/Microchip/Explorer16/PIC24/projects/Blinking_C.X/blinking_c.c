/*
 * File:   blinking_c.c
 * Author: fercho
 *
 * Created on March 15, 2024, 5:12 PM
 */


#include "xc.h"



#define FCY 8000000UL

#pragma config POSCMOD = HS
#pragma config OSCIOFNC = OFF
#pragma config FCKSM = CSDCMD
#pragma config FNOSC = PRIPLL
#pragma config IESO = OFF
#pragma config WDTPS = PS32768
#pragma config FWPSA = PR128
#pragma config WINDIS = ON
#pragma config FWDTEN = OFF
#pragma config ICS = PGx2
#pragma config GWRP = OFF
#pragma config GCP = OFF
#pragma config JTAGEN = OFF

#include <libpic30.h>

int main(void) {
    TRISAbits.TRISA0 = 0;   // puerto A0 como salida
    
    while(0 == 0) {
        LATAbits.LATA0 = 1;     // enciende el LED
        __delay_ms(500);
        LATAbits.LATA0 = 0;     // enciende el LED
        __delay_ms(500);
    }
    
    return 0;
}
