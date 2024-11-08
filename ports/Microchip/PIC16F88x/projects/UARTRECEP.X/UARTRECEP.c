/*
 * File:   UARTRECEP.c
 * Author: LUIS PINTO
 *
 * Created on 11 de febrero de 2024, 10:25 AM
 */

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#include <stdio.h>
#define XTAL_FREQ 8000000

#include "../../api/builtin.c"
#include "../../api/machine/pin.c"
#include "../../api/machine/uart.c"

char datos;

void main(void) {
    
    ANSELH = 0b00000000;
    ANSEL  = 0b00000000;
    
    pin.setup(pin.c0_s,out);
    pin.setup(pin.c1_s,out);
    
    pin.write(pin.c0,0);
    pin.write(pin.c1,0);
    
    uart.setup();

    while(1){
        
        if(uart.input ()> 0){
                       
            datos = uart.read();
        
        }
        
        switch (datos){
            
            case 'a':
                
                pin.high(pin.c0);
                print("led1: Encendido\r\n");
                break;  
                
            case 'b':
                
                pin.low(pin.c0);
                print("led1: Apagado\r\n");
                break;
                
            case 'q':
                
                pin.high(pin.c1);
                print("led1: Encendido\r\n");
                break;  
                
            case 'w':
                
                pin.low(pin.c1);
                print("led1: Apagado\r\n");
                break;
        }
    
    }
}
