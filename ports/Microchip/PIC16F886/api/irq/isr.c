void __interrupt() isr(void) {
    if(INTCONbits.INTE && INTCONbits.INTF) {
        irq_external();
        INTCONbits.INTF = 0;
    }
    // if(INTCONbits.T0IE && INTCONbits.T0IF) {
    //     irq_timer0();
    //     INTCONbits.T0IF = 0;
    // }
    return;
}