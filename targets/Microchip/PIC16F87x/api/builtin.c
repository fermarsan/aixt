#define _XTAL_FREQ _const_main__cpu_freq

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#if defined(_const_timer0__irq_in_use) || defined(_const_ext__irq_in_use)   // if any interrupt source is activated

#ifdef _const_ext__irq_in_use
void (*ptr_ext_isr)(void);      // Interrupt Service Routine pointer
#endif  // _const_ext__irq_in_use

#ifdef _const_timer0__irq_in_use
void (*ptr_timer0_isr)(void);   // Interrupt Service Routine pointer
#endif  // _const_timer0__irq_in_use

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
