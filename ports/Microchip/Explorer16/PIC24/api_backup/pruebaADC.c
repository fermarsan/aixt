// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2022 Santiago Orjuela R
/*
** It?s an analog world
** Converting the analog signal from a potentiometer
*/
#include<p24FJ128GA010.h>
#include<libpic30.h>
#define POT 5 // 10k potentiometer connected to AN5 input
#define AINPUTS 0xffdf // Analog inputs for Explorer16 POT and TSENS
#define    FCY    8000000UL    // Instruction cycle frequency, Hz - required for __delayXXX() to work

void initADC (int amask)
{

AD1CON1 = 0x00E0; // automatic conversion start after sampling
AD1CSSL = 0; // no scanning required
AD1CON2 = 0; // use MUXA, AVss and AVdd are used as Vref+/-
AD1CON3 = 0x1F02; // Tsamp = 32 x Tad; Tad=125ns
AD1CON1bits.ADON = 1; // turn on the ADC
} //initADC
int readADC (int ch)
{
AD1CHS = ch; // 1. select analog input channel
AD1CON1bits.SAMP = 1; // 2. start sampling
while (!AD1CON1bits.DONE); // 3. wait for the conversion to complete
return ADC1BUF0; // 4. read the conversion result
} // readADC
main ()
{
int a;
// initializations
initADC( AINPUTS); // initialize the ADC for the Explorer16 analog inputs
TRISA = 0xff00; // select the PORTA pins as outputs to drive the LEDs
// main loop
while(1)
{
a = readADC( POT); // select the POT input and convert
// reduce the 10-bit result to a 3 bit value (0..7)
// (divide by 128 or shift right 7 times
a >>= 7;
// turn on only the corresponding LED
// 0 -> leftmost LED.... 7-> rightmost LED
PORTA = (0x80 >> a);
} // main loop
} // main