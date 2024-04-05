// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
//
// Description: Builtin definitions (Explorer16-PIC24 port)
module main

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

// ----------  if setup.c.v doesn't found  ----------
// #ifndef __setup__

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

// #endif
// --------------------------------------------------

#define led3    A, 0	// Onboard LEDs            
#define led4    A, 1        
#define led5    A, 2        
#define led6    A, 3       
#define led7    A, 4       
#define led8    A, 5        
#define led9    A, 6        
#define led10   A, 7    

#define sw3     D, 6	// Onboard switchs  
#define sw4     D, 13  
#define sw5     A, 7  
#define sw6     D, 7  

#define pot     B, 5	// Onboard potentiometer

fn init() {
	AD1PCFG = 0xFFDF      	// Analog inputs for Explorer16 POT and TSENS
	AD1CSSL = 0           	// no scanning required
	AD1CON2 = 0           	// use MUXA, AVss and AVdd are used as Vref+/-
	AD1CON3 = 0x1F02      	// Tsamp = 32 x Tad; Tad=125ns
	AD1CON1bits.ADON = 1  	// turn on the ADC
	
	TRISA = 0xff00        	// select the PORTA pins as outputs to drive the LEDs

	TRISDbits.TRISD6 =  1	// inputs switches
	TRISDbits.TRISD13 = 1	 
	TRISDbits.TRISD7 =  1	 
	TRISBbits.TRISB5 =  1	// potentiometer
}