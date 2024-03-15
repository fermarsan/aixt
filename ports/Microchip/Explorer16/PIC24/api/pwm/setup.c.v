module pwm


fn setup(output u8, freq u16) {
	if output == 1 {
		TRISCbits.TRISC2 = 0
		CCPR1L = 0
		CCP1CON = 0x0C
	} else if output == 2 {
		TRISCbits.TRISC1 = 0
		CCPR2L = 0
		CCP2CON = 0x0C
	} else {
		TRISCbits.TRISC2 = 0
		CCPR1L = 0
		TRISCbits.TRISC1 = 0
		CCPR2L = 0
		CCP1CON = 0x0C
		CCP2CON = 0x0C
	}

	PR2 = 0x0C                   // Valor del período del PWM 
    T2CON = 0x03                 // Configuración del Timer 2
    TMR2 = 0                     // Inicializa el Timer 2 en 0 
    T2CONbits.TMR2ON = 1         // Enciende el Timer 2 
}