__attribute__((interrupt("WCH-Interrupt-fast")))
__attribute__((section(".highcode")))
void global_isr(void) {
    #ifdef irq_uart_rx_isr_exists
        if(UART_II_RECV_TOUT) {
            isr_uart_rx();
        }
    #endif
   return;
}