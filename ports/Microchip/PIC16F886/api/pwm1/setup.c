#define setup(FPWM) \
    PR2 = 199;  \
    CCPR2L = 0;  \
    TRISCbits.TRISC1 = 0;   \
    T2CON = 0b00000011;     \
    CCP2CON = 0b00001100;   \
    TMR2 = 0;   \
    T2CONbits.TMR2ON = 1;   \             
