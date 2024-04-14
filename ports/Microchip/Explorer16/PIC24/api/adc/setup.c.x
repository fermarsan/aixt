void setup() {// setup function
    AD1PCFG = 0xffdf;        // Analog inputs for Explorer16 POT and TSENS

    // ASAM enabled; ADSIDL disabled; DONE disabled; FORM Absolute decimal result, unsigned, right-justified; SAMP disabled; SSRC Internal counter ends sampling and starts conversion; ADON enabled; 
    AD1CON1 = 0x80E4;

    // CSCNA disabled; VCFG0 AVDD; VCFG1 AVSS; ALTS disabled; BUFM disabled; SMPI Generates interrupt after completion of every sample/conversion operation; 
    AD1CON2 = 0x0000;

    // SAMC 31; ADRC RC clock; ADCS 0; 
    AD1CON3 = 0x9F00;

    // CH0SA AN5; CH0SB AN5; CH0NB AVSS; CH0NA AVSS; 
    AD1CHS = 0x0505;

    // CSSL9 disabled; CSSL8 disabled; CSSL7 disabled; CSSL6 disabled; CSSL5 disabled; CSSL4 disabled; CSSL3 disabled; CSSL2 disabled; CSSL15 disabled; CSSL1 disabled; CSSL14 disabled; CSSL0 disabled; CSSL13 disabled; CSSL12 disabled; CSSL11 disabled; CSSL10 disabled; 
    AD1CSSL = 0x0000;
}