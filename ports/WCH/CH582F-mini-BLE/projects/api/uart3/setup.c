void setup(uint32_t baud_rate){
    UART3_BaudRateCfg(baud_rate);
    R8_UART3_FCR = (2 << 6) | RB_FCR_TX_FIFO_CLR | RB_FCR_RX_FIFO_CLR | RB_FCR_FIFO_EN;
    R8_UART3_LCR = RB_LCR_WORD_SZ;
    R8_UART3_IER = RB_IER_TXD_EN;
    R8_UART3_DIV = 1;

    GPIOA_SetBits(GPIO_Pin_5);
    GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeIN_PU);   //RX
    GPIOA_ModeCfg(GPIO_Pin_5, GPIO_ModeOut_PP_5mA);  //TX
}