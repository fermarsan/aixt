__attribute__((interrupt("WCH-Interrupt-fast")))
__attribute__((section(".highcode")))
void global_isr(void) {
    #ifdef irq_uart3_rx_isr_exists
        if(UART3_II_RECV_TOUT) {
            isr_uart3_rx();
        }
    #endif
   return;
}