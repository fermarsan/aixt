
#define _XTAL_FREQ _const_main__cpu_freq

#pragma config MCLRE = OFF      // Master Clear Enable
#pragma config CP = OFF         // Code Protection
#pragma config BOREN = OFF      // Brown-out Reset Enable
#pragma config WDTE = OFF       // Watchdog Timer Enable
#pragma config FOSC = INTRCIO   // Internal RC oscilator
#pragma config PWRTE = ON       // Power-up timer

#if defined(_const_timer0__irq_in_use) || defined(_const_ext__irq_in_use)   // if any interrupt source is activated

// #ifdef _const_ext__irq_in_use
// void (*ptr_ext_isr)(void);      // Interrupt Service Routine pointer
// #endif  // _const_ext__irq_in_use

// #ifdef _const_timer0__irq_in_use
// void (*ptr_timer0_isr)(void);   // Interrupt Service Routine pointer
// #endif  // _const_timer0__irq_in_use

void __interrupt() Global_ISR() {
    #ifdef _const_ext__irq_in_use
        if(INTF == 1) {
            ptr_ext_isr();
            INTF = 0;
        }
    #endif  // _const_ext__irq_in_use

    #ifdef _const_timer0__irq_in_use
        if(T0IF == 1) {
            ptr_timer0_isr();
            T0IF = 0;
        }
    #endif  // _const_timer0__irq_in_use
}

#endif  // defined(_const_timer0__irq_in_use) || defined(_const_ext__irq_in_use)
