void setup(uint32_t baud_rate){
    UART2_BaudRateCfg(baud_rate);
    R8_UART2_FCR = (2 << 6) | RB_FCR_TX_FIFO_CLR | RB_FCR_RX_FIFO_CLR | RB_FCR_FIFO_EN;
    R8_UART2_LCR = RB_LCR_WORD_SZ;
    R8_UART2_IER = RB_IER_TXD_EN;
    R8_UART2_DIV = 1;

    GPIOB_SetBits(GPIO_Pin_23);
    GPIOB_ModeCfg(GPIO_Pin_22, GPIO_ModeIN_PU);   //RX
    GPIOB_ModeCfg(GPIO_Pin_23, GPIO_ModeOut_PP_5mA);  //TX
}