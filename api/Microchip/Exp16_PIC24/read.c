uint16_t read(uint8_t channel) {		// read the converted value
    AD1CHS = channel;           // 1. select analog input channel
    AD1CON1bits.SAMP = 1;       // 2. start sampling
    __delay32(3);               // 3. sampling time (3 cycles + 1)
    AD1CON1bits.SAMP = 0;       // 4. start conventing
    while(!AD1CON1bits.DONE);	// 5. wait for the conversion to complete
    return ADC1BUF0;			// 6. read the conversion result
}