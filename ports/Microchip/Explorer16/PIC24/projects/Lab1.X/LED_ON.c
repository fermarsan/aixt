/*
 * File:   LED_ON.c
 * Author: Fernando Martínez Santa
 * 
 * Created on March 21, 2024, 4:49 PM
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

int main(void) {
    
    TRISAbits.TRISA0 = 0;   // configura PA0 como salida
    
    while(1) {
        LATAbits.LATA0 = 1;     // enciende el LED de PA0
    }
    
    return 0;
}
