
#define _XTAL_FREQ _const_main__cpu_freq

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#if defined(TIMER0_IRQ_IN_USE) || defined(EXT_IRQ_IN_USE)   // if any interrupt source is activated

// #ifdef EXT_IRQ_IN_USE    
// void (*ptr_ext_isr)(void);      // Interrupt Service Routine pointer
// #endif  // EXT_IRQ_IN_USE 

// #ifdef TIMER0_IRQ_IN_USE    
// void (*ptr_timer0_isr)(void);   // Interrupt Service Routine pointer
// #endif  // TIMER0_IRQ_IN_USE 

void __interrupt() Global_ISR() {
    #ifdef EXT_IRQ_IN_USE    
        if(INTF == 1) {
            ptr_ext_isr();
            INTF = 0;
        }
    #endif  // EXT_IRQ_IN_USE 

    #ifdef TIMER0_IRQ_IN_USE    
        if(T0IF == 1) {
            ptr_timer0_isr();
            T0IF = 0;
        }
    #endif  // TIMER0_IRQ_IN_USE 
}

#endif  // defined(TIMER0_IRQ_IN_USE) || defined(EXT_IRQ_IN_USE)

