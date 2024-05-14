
#define setup(PINS, FAD) \
    /* analog pins setup */ \
    ANSEL = (uint8_t)~PINS;         \
    ANSELH = (uint8_t)(~PINS>>8);   \
    /* ADC setup */ \
    ADCON1 = 0b10000000;    /*Right justified, VSS, VDD*/\
    ADCON0bits.ADCS = FAD;  \
    ADCON0bits.ADON = 1;
