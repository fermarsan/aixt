void __interrupt() global_isr(void) {
    #ifdef irq_external_isr_exists
        if(INTCONbits.INTE && INTCONbits.INTF) {
            isr_external();
            INTCONbits.INTF = 0;
        }
    #endif
    #ifdef irq_timer0_isr_exists
        if(INTCONbits.T0IE && INTCONbits.T0IF) {
            isr_timer0();
            INTCONbits.T0IF = 0;
        }
    #endif
    return;
}