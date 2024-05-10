inline void setup() {
    ANSEL = 0b00000100;     /* Configures the AN1 pin as analog input */ 
    ADCON0 = 0b10000000;    /* Enables the ADC and selects AN1 as input */
    ADCON1 = 0b00110000;    /* Sets the voltage reference */
    ADCON0bits.ADON = 1;    /* Turns on ADC converter */
}