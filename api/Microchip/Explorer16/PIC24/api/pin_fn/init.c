void init() {// setup function
    AD1PCFG = 0xffdf;   // Analog inputs for Explorer16 POT and TSENS
    AD1CON1 = 0x80E4;   // ASAM enabled; ADSIDL disabled; DONE disabled; FORM Absolute decimal result, unsigned, right-justified; SAMP disabled; SSRC Internal counter ends sampling and starts conversion; ADON enabled; 
    AD1CON2 = 0x0000;   // CSCNA disabled; VCFG0 AVDD; VCFG1 AVSS; ALTS disabled; BUFM disabled; SMPI Generates interrupt after completion of every sample/conversion operation; 
    AD1CON3 = 0x1F00;   // SAMC 31; ADRC FOSC/2; ADCS 0;
    AD1CHS = 0x0000;    // CH0SA AN5; CH0SB AN5; CH0NB AVSS; CH0NA AVSS;
    AD1CSSL = 0x0000;   // CSSL9 disabled; CSSL8 disabled; CSSL7 disabled; CSSL6 disabled; CSSL5 disabled; CSSL4 disabled; CSSL3 disabled; CSSL2 disabled; CSSL15 disabled; CSSL1 disabled; CSSL14 disabled; CSSL0 disabled; CSSL13 disabled; CSSL12 disabled; CSSL11 disabled; CSSL10 disabled;
}