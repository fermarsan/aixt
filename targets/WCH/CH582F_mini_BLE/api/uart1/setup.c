void setup(uint32_t baud_rate){
    uint8_t TxBuff[] = "";
    uint8_t RxBuff[100];
    
    UART1_BaudRateCfg(baud_rate);
    R8_UART1_FCR = (2 << 6) | RB_FCR_TX_FIFO_CLR | RB_FCR_RX_FIFO_CLR | RB_FCR_FIFO_EN;
    R8_UART1_LCR = RB_LCR_WORD_SZ;
    R8_UART1_IER = RB_IER_TXD_EN;
    R8_UART1_DIV = 1;

    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);   //RX
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);  //TX
}