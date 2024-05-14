void setup(uint8_t freq) {
    ADCON1 = 0b10000000; 
    ADCON0 = 0b11001000; 
    ADCON0bits.ADON = 1;
}