unit16_t read(unit8_t channel) {
    ADCON0bits.CHS = channel;   // assign the ADC channel
    ADCON0bits.GO_DONE = 1;      // start conversion
    while(ADCON0bits.GO_DONE == 1) {}   // wait for the end of conversion
    return (ADRESH << 8) | ADRESL;      // return the ADC value
}