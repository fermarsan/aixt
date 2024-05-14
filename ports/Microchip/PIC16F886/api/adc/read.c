#define read(CHANNEL) ({    \
    ADCON0bits.CHS = CHANNEL;   /* assign the ADC channel */    \
    ADCON0bits.GO_DONE = 1;     /* start conversion */  \
    while(ADCON0bits.GO_DONE == 1) {}   /* wait for the end of conversion */    \
    (ADRESH << 8) | ADRESL;     /* return the ADC value */  \
})