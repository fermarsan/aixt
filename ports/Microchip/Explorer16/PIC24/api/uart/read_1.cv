void UART2_Write(uint8_t txData)
{
    while(U2STAbits.UTXBF == 1)
    {
    }

    U2TXREG = txData;    // Write the data byte to the USART.
}