inline uint16_t read(uint8_t channel) {
    ADCON0bits.CHS = channel;           // Asigna el canal del ADC  
    ADCON0bits.GO_DONE = 1;             // Inicia la conversion
    while(ADCON0bits.GO_DONE == 1) {}
    return ((ADRESH << 8) | ADRESL);    /* Devuelve el valor del ADC */
}