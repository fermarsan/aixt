
#define _XTAL_FREQ _const_main__cpu_freq

#pragma config FCMEN = OFF     // Fail-Safe Clock Monitor Enable
#pragma config IESO = OFF      // Internal/External Switchover
#pragma config MCLRE = OFF     // Master Clear Enable
#pragma config CP = OFF        // Code Protection
#pragma config BOREN = OFF     // Brown-out Reset Enable
#pragma config WDT = OFF       // Watchdog Timer Enable

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

