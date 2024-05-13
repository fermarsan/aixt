void write(char data){
    while(U2STAbits.UTXBF == 1){}
    U2TXREG = (uint8_t)data;    // Write the data byte to the USART.
}