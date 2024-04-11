int read(int channel) {		// read the converted value
    AD1CHS = channel;           // 1. select analog input channel
    AD1CON1bits.SAMP = 1;       // 2. start sampling
    while(!AD1CON1bits.DONE);	// 3. wait for the conversion to complete
    return ADC1BUF0;			// 4. read the conversion result
}