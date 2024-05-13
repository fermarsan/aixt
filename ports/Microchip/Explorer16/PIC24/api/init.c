void init() {
	AD1PCFG = 0xFFDF;     	// Analog inputs for Explorer16 POT and TSENS
	AD1CSSL = 0;           	// no scanning required
	AD1CON2 = 0;           	// use MUXA, AVss and AVdd are used as Vref+/-
	AD1CON3 = 0x1F02;      	// Tsamp = 32 x Tad; Tad=125ns
	AD1CON1bits.ADON = 1;  	// turn on the ADC

	TRISA = 0xff00;        	// select the PORTA pins as outputs to drive the LEDs
	TRISDbits.TRISD6 =  1;	// inputs switches
	TRISDbits.TRISD13 = 1;	 
	TRISDbits.TRISD7 =  1;	 
	TRISBbits.TRISB5 =  1;	// potentiometer
}